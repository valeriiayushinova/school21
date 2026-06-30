package web

import "github.com/google/uuid"

// GameResponse — модель игры для возврата через API
type GameResponse struct {
	ID            uuid.UUID `json:"id"`
	Board         [3][3]int `json:"board"`
	CurrentPlayer int       `json:"current_player"`
	Status        string    `json:"status"`
}

// MoveResponse — модель хода для возврата через API
type MoveResponse struct {
	Row, Col int `json:"row" json:"col"`
	Player   int `json:"player"`
}
