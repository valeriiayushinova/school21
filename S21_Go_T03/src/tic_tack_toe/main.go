package main

import (
	"context"
	"log"
	"net/http"
	"sync"
	"tic_tac_toe/datasource/repository"
	"tic_tac_toe/domain"
	"tic_tac_toe/web"

	"github.com/gorilla/mux"
	"go.uber.org/fx"
)

// GameStorage — структура для хранения игр
type GameStorage struct {
	games *sync.Map
}

// NewGameStorage — конструктор для создания структуры хранения
func NewGameStorage() *GameStorage {
	return &GameStorage{
		games: &sync.Map{},
	}
}

func main() {
	app := fx.New(
		fx.Provide(
			func() *sync.Map {
				return &sync.Map{}
			},
			repository.NewFileRepository,
			domain.NewGameService,
			web.NewGameHandler,
			func() *mux.Router {
				return mux.NewRouter()
			},
		),

		fx.Invoke(registerRoutes),
	)

	app.Run()
}

func registerRoutes(lc fx.Lifecycle, router *mux.Router, handler *web.GameHandler) {
	router.HandleFunc("/game", handler.CreateGame).Methods("POST")
	router.HandleFunc("/game/{id}", handler.GetGame).Methods("GET")
	router.HandleFunc("/game/{current_game_UUID}", handler.UpdateGame).Methods("POST")

	lc.Append(fx.Hook{
		OnStart: func(ctx context.Context) error {
			log.Println("Starting server on :8080")
			go func() {
				if err := http.ListenAndServe(":8080", router); err != nil && err != http.ErrServerClosed {
					log.Fatalf("listen: %s\n", err)
				}
			}()
			return nil
		},
		OnStop: func(ctx context.Context) error {
			log.Println("Stopping server...")
			return nil
		},
	})
}
