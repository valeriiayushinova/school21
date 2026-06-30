package repository

import (
	"errors"
	"tic_tac_toe/datasource/model"
)

var (
	ErrGameNotFound  = errors.New("game not found")
	ErrCellOccupied  = errors.New("cell is already occupied")
	ErrInvalidPlayer = errors.New("invalid player")
)

type GameRepository interface {
	// SaveGame сохраняет состояние игры
	SaveGame(game *model.GameDTO) error
	// LoadGame загружает игру по идентификатору
	LoadGame(id string) (*model.GameDTO, error)
}
