package di

import (
	"sync"
	"tic_tac_toe/datasource"
	"tic_tac_toe/domain"
	"tic_tac_toe/web"
)

// Container — структура для хранения зависимостей
type Container struct {
	GameRepository datasource.GameRepository
	GameService    datasource.GameService
	GameHandler    *web.GameHandler
}

// NewContainer — конструктор для создания контейнера зависимостей
func NewContainer() *Container {
	gamesStorage := &sync.Map{}

	repo := datasource.NewInMemoryGameRepository(gamesStorage)

	service := domain.NewGameService(repo)

	handler := web.NewGameHandler(service, repo)

	return &Container{
		GameRepository: repo,
		GameService:    &service,
		GameHandler:    handler,
	}
}
