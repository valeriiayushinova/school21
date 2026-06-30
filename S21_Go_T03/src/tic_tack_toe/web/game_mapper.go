package web

import (
	dto "tic_tac_toe/datasource/model"
	"tic_tac_toe/domain"
)

// ToGameDTO преобразует доменную модель Game в DTO
func ToGameDTO(game domain.Game) *dto.GameDTO {
	dtoGame := &dto.GameDTO{
		ID:            game.ID,
		CurrentPlayer: int(game.CurrentPlayer),
		Status:        game.Status,
	}

	for i := 0; i < 3; i++ {
		for j := 0; j < 3; j++ {
			switch game.Board[i][j] {
			case domain.Empty:
				dtoGame.Board[i][j] = 0
			case domain.Cross:
				dtoGame.Board[i][j] = 1
			case domain.Circle:
				dtoGame.Board[i][j] = 2
			}
		}
	}

	return dtoGame
}

// ToGame преобразует DTO обратно в доменную модель Game
func ToGame(dtoGame *dto.GameDTO) *domain.Game {
	game := &domain.Game{
		ID:            dtoGame.ID,
		CurrentPlayer: dtoGame.CurrentPlayer,
		Status:        dtoGame.Status,
	}

	for i := 0; i < 3; i++ {
		for j := 0; j < 3; j++ {
			switch dtoGame.Board[i][j] {
			case 0:
				game.Board[i][j] = domain.Empty
			case 1:
				game.Board[i][j] = domain.Cross
			case 2:
				game.Board[i][j] = domain.Circle
			}
		}
	}

	return game
}
