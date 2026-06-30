package repository


import (
	"sync"
	"tic_tac_toe/datasource/model"
)

// InMemoryGameRepository — структура для работы с играми в памяти
type InMemoryGameRepository struct {
	games *sync.Map
}

// NewInMemoryGameRepository — конструктор для создания репозитория в памяти
func NewInMemoryGameRepository(games *sync.Map) GameRepository {
	return &InMemoryGameRepository{games: games}
}

// SaveGame — сохранение игры
func (r *InMemoryGameRepository) SaveGame(game *model.GameDTO) error {
	r.games.Store(game.ID.String(), game)
	return nil
}

// LoadGame — загрузка игры
func (r *InMemoryGameRepository) LoadGame(id string) (*model.GameDTO, error) {
	value, exists := r.games.Load(id)
	if !exists {
		return nil, ErrGameNotFound
	}
	return value.(*model.GameDTO), nil
}
