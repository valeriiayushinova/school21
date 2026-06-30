package model

import "github.com/google/uuid"

// GameDTO — модель для хранения состояния игры
type GameDTO struct {
	ID            uuid.UUID `json:"id"`             // Уникальный идентификатор игры
	Board         [3][3]int `json:"board"`          // Игровое поле (0 — пусто, 1 — крестик, 2 — нолик)
	CurrentPlayer int       `json:"current_player"` // Текущий игрок (1 или 2)
	Status        string    `json:"status"`         // Статус игры
}
