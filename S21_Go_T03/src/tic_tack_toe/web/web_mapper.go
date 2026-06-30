package web

import (
	"tic_tac_toe/domain"
)

// ToGameResponse преобразует доменную модель Game в веб-модель GameResponse
func ToGameResponse(game domain.Game) *GameResponse {
	response := &GameResponse{
		ID:            game.ID,
		CurrentPlayer: game.CurrentPlayer,
		Status:        game.Status,
	}

	// Преобразуем игровое поле
	for i := 0; i < 3; i++ {
		for j := 0; j < 3; j++ {
			switch game.Board[i][j] {
			case domain.Empty:
				response.Board[i][j] = 0
			case domain.Cross:
				response.Board[i][j] = 1
			case domain.Circle:
				response.Board[i][j] = 2
			}
		}
	}

	return response
}

// ToMoveResponse преобразует доменную модель Move в веб-модель MoveResponse
func ToMoveResponse(move domain.Move) MoveResponse {
	player := 0
	if move.Player == domain.Cross {
		player = 1
	} else if move.Player == domain.Circle {
		player = 2
	}

	return MoveResponse{
		Row:    move.Row,
		Col:    move.Col,
		Player: player,
	}
}
