package domain

import (
	"log"
	"math"
	"tic_tac_toe/datasource/repository"
)

type gameService struct {
	repo repository.GameRepository
}

// NewGameService создаёт новый сервис
func NewGameService(repo repository.GameRepository) GameService {
	return &gameService{repo: repo}
}

// CalculateNextMove — вычисляет следующий ход с использованием алгоритма минимакса
func (s *gameService) CalculateNextMove(game *Game) Move {
	bestMove := Move{Row: -1, Col: -1}
	bestScore := math.MinInt32
	currentPlayer := game.CurrentPlayer
	opponent := 2
	if currentPlayer == 2 {
		opponent = 1
	}

	log.Printf("Calculating next move for opponent: %d\n", opponent)

	for i := 0; i < 3; i++ {
		for j := 0; j < 3; j++ {
			if game.Board[i][j] == Empty {
				game.Board[i][j] = CellState(opponent)
				if gameOver, winner := s.IsGameOver(game); gameOver && winner == opponent {
					game.Board[i][j] = Empty
					bestMove.Row = i
					bestMove.Col = j
					bestMove.Player = CellState(opponent)
					log.Printf("Winning move for player %d: (%d, %d)\n", opponent, bestMove.Row, bestMove.Col)
					return bestMove
				}
				game.Board[i][j] = Empty
			}
		}
	}

	for i := 0; i < 3; i++ {
		for j := 0; j < 3; j++ {
			if game.Board[i][j] == Empty {
				game.Board[i][j] = CellState(currentPlayer)
				if gameOver, _ := s.IsGameOver(game); gameOver {
					game.Board[i][j] = Empty
					bestMove.Row = i
					bestMove.Col = j
					bestMove.Player = CellState(opponent)
					log.Printf("Blocking move for player %d: (%d, %d)\n", opponent, bestMove.Row, bestMove.Col)
					return bestMove
				}
				game.Board[i][j] = Empty
			}
		}
	}

	for i := 0; i < 3; i++ {
		for j := 0; j < 3; j++ {
			if game.Board[i][j] == Empty {
				game.Board[i][j] = CellState(opponent)
				score := s.minimax(game, 0, false)
				game.Board[i][j] = Empty

				if score > bestScore {
					bestScore = score
					bestMove.Row = i
					bestMove.Col = j
				}
			}
		}
	}

	bestMove.Player = CellState(opponent)
	log.Printf("Best move for player %d: (%d, %d)\n", opponent, bestMove.Row, bestMove.Col)
	return bestMove
}

// minimax — рекурсивная функция для оценки ходов
func (s *gameService) minimax(game *Game, depth int, isMaximizing bool) int {
	gameOver, winner := s.IsGameOver(game)
	if gameOver {
		if winner == 1 {
			return 10 - depth
		} else if winner == 2 {
			return -10 + depth
		} else {
			return 0
		}
	}

	if isMaximizing {
		bestScore := math.MinInt32
		for i := 0; i < 3; i++ {
			for j := 0; j < 3; j++ {
				if game.Board[i][j] == Empty {
					game.Board[i][j] = Cross
					score := s.minimax(game, depth+1, false)
					game.Board[i][j] = Empty
					bestScore = int(math.Max(float64(score), float64(bestScore)))
				}
			}
		}
		return bestScore
	} else {
		bestScore := math.MaxInt32
		for i := 0; i < 3; i++ {
			for j := 0; j < 3; j++ {
				if game.Board[i][j] == Empty {
					game.Board[i][j] = Circle
					score := s.minimax(game, depth+1, true)
					game.Board[i][j] = Empty
					bestScore = int(math.Min(float64(score), float64(bestScore)))
				}
			}
		}
		return bestScore
	}
}

// IsGameOver — проверка завершения игры
func (s *gameService) IsGameOver(game *Game) (bool, int) {
	for i := 0; i < 3; i++ {
		if game.Board[i][0] != Empty && game.Board[i][0] == game.Board[i][1] && game.Board[i][1] == game.Board[i][2] {
			if game.Board[i][0] == Cross {
				return true, 1
			} else {
				return true, 2
			}
		}
	}

	for j := 0; j < 3; j++ {
		if game.Board[0][j] != Empty && game.Board[0][j] == game.Board[1][j] && game.Board[1][j] == game.Board[2][j] {
			if game.Board[0][j] == Cross {
				return true, 1
			} else {
				return true, 2
			}
		}
	}

	if game.Board[0][0] != Empty && game.Board[0][0] == game.Board[1][1] && game.Board[1][1] == game.Board[2][2] {
		if game.Board[0][0] == Cross {
			return true, 1
		} else {
			return true, 2
		}
	}
	if game.Board[0][2] != Empty && game.Board[0][2] == game.Board[1][1] && game.Board[1][1] == game.Board[2][0] {
		if game.Board[0][2] == Cross {
			return true, 1
		} else {
			return true, 2
		}
	}

	for i := 0; i < 3; i++ {
		for j := 0; j < 3; j++ {
			if game.Board[i][j] == Empty {
				return false, 0
			}
		}
	}

	return true, 0
}

// ValidateBoard — проверка корректности игрового поля
func (s *gameService) ValidateBoard(game *Game) bool {
	crossCount := 0
	circleCount := 0

	for i := 0; i < 3; i++ {
		for j := 0; j < 3; j++ {
			if game.Board[i][j] == Cross {
				crossCount++
			} else if game.Board[i][j] == Circle {
				circleCount++
			}
		}
	}

	if crossCount-circleCount > 1 || circleCount-crossCount > 0 {
		return false
	}

	return true
}

// ValidateMove — проверка корректности хода
func (s *gameService) ValidateMove(game *Game, lastMove Move) error {
	if game.Board[lastMove.Row][lastMove.Col] != Empty {
		return repository.ErrCellOccupied
	}

	expectedPlayer := CellState(game.CurrentPlayer)
	if lastMove.Player != expectedPlayer {
		return repository.ErrInvalidPlayer
	}

	return nil
}
