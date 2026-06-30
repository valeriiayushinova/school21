package web

import (
	"encoding/json"
	"log"
	"net/http"
	"tic_tac_toe/datasource/repository"
	"tic_tac_toe/domain"

	"github.com/google/uuid"
	"github.com/gorilla/mux"
)

// GameHandler — структура для обработки HTTP-запросов
type GameHandler struct {
	service domain.GameService
	repo    repository.GameRepository
}

// NewGameHandler создаёт новый обработчик
func NewGameHandler(service domain.GameService, repo repository.GameRepository) *GameHandler {
	return &GameHandler{service: service, repo: repo}
}

// CreateGame — метод для создания новой игры
func (h *GameHandler) CreateGame(w http.ResponseWriter, r *http.Request) {
	log.Println("CreateGame handler called")

	game := &domain.Game{
		ID:            uuid.New(),
		Board:         domain.Board{},
		CurrentPlayer: 1,
		Status:        "active",
	}

	dtoGame := ToGameDTO(*game)
	err := h.repo.SaveGame(dtoGame)
	if err != nil {
		log.Printf("Error saving game: %v", err)
		http.Error(w, err.Error(), http.StatusInternalServerError)
		return
	}

	response := ToGameResponse(*game)
	w.Header().Set("Content-Type", "application/json")
	if err := json.NewEncoder(w).Encode(response); err != nil {
		log.Printf("Error encoding response: %v", err)
	}
}

// GetGame — метод для получения информации об игре
func (h *GameHandler) GetGame(w http.ResponseWriter, r *http.Request) {
	vars := mux.Vars(r)
	id := vars["id"]
	if id == "" {
		http.Error(w, "missing game id", http.StatusBadRequest)
		return
	}

	dtoGame, err := h.repo.LoadGame(id)
	if err != nil {
		http.Error(w, err.Error(), http.StatusNotFound)
		return
	}

	game := ToGame(dtoGame)
	response := ToGameResponse(*game)

	w.Header().Set("Content-Type", "application/json")
	json.NewEncoder(w).Encode(response)
}

func (h *GameHandler) UpdateGame(w http.ResponseWriter, r *http.Request) {
	vars := mux.Vars(r)
	gameUUID, err := uuid.Parse(vars["current_game_UUID"])
	if err != nil {
		http.Error(w, "invalid game UUID", http.StatusBadRequest)
		return
	}

	var updatedGame domain.Game
	err = json.NewDecoder(r.Body).Decode(&updatedGame)
	if err != nil {
		http.Error(w, err.Error(), http.StatusBadRequest)
		return
	}

	if updatedGame.ID != gameUUID {
		http.Error(w, "game UUID mismatch", http.StatusBadRequest)
		return
	}

	previousGameDTO, err := h.repo.LoadGame(updatedGame.ID.String())
	if err != nil {
		http.Error(w, "failed to load previous game state", http.StatusInternalServerError)
		return
	}
	previousGame := ToGame(previousGameDTO)

	var lastMove domain.Move
	for i := 0; i < 3; i++ {
		for j := 0; j < 3; j++ {
			if previousGame.Board[i][j] != updatedGame.Board[i][j] {
				lastMove = domain.Move{Row: i, Col: j, Player: updatedGame.Board[i][j]}
				break
			}
		}
	}

	err = h.service.ValidateMove(previousGame, lastMove)
	if err != nil {
		http.Error(w, err.Error(), http.StatusBadRequest)
		return
	}

	gameOver, winner := h.service.IsGameOver(&updatedGame)
	if !gameOver {
		computerMove := h.service.CalculateNextMove(&updatedGame)
		updatedGame.Board[computerMove.Row][computerMove.Col] = computerMove.Player
		gameOver, winner = h.service.IsGameOver(&updatedGame)
	}

	if gameOver {
		updatedGame.Status = "finished"
		if winner == 0 {
			updatedGame.Status = "draw"
		}
	} else {
		if updatedGame.CurrentPlayer == 1 {
			updatedGame.CurrentPlayer = 2
		} else {
			updatedGame.CurrentPlayer = 1
		}
	}

	dtoGame := ToGameDTO(updatedGame)
	err = h.repo.SaveGame(dtoGame)
	if err != nil {
		http.Error(w, err.Error(), http.StatusInternalServerError)
		return
	}

	response := ToGameResponse(updatedGame)
	w.Header().Set("Content-Type", "application/json")
	json.NewEncoder(w).Encode(response)
}
