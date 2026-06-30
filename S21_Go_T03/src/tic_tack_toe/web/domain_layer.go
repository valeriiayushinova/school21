package web

// CellState — возможные состояния клетки на поле
type CellState int

const (
	Empty CellState = iota
	Cross
	Circle
)

// Board — игровое поле 3×3
type Board [3][3]CellState
