package domain



type GameService interface {
	// CalculateNextMove вычисляет следующий ход с использованием алгоритма минимакса
	CalculateNextMove(game *Game) Move

	// ValidateBoard проверяет корректность игрового поля
	ValidateBoard(game *Game) bool

	// IsGameOver проверяет завершение игры
	IsGameOver(game *Game) (bool, int) // (завершена, победитель: 0 — ничья, 1 или 2 — игрок)

	// ValidateMove метод для проверки корректности хода
	ValidateMove(game *Game, lastMove Move) error
}
