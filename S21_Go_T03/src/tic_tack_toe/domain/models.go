package domain

import "github.com/google/uuid"

// CellState — возможные состояния клетки на поле
type CellState int

const (
	Empty CellState = iota
	Cross
	Circle
)

// Board — игровое поле 3×3
type Board [3][3]CellState

// Game — модель текущей игры
type Game struct {
	ID            uuid.UUID
	Board         Board
	CurrentPlayer int
	Status        string
}

// Move — модель хода игрока
type Move struct {
	Row, Col int
	Player   CellState
}
