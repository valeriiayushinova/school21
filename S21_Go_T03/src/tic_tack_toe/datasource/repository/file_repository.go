package repository

import (
	"encoding/json"
	"fmt"
	"os"
	"path/filepath"
	"sync"
	"tic_tac_toe/datasource/model" // Убедитесь, что путь к DTO верный
)

type fileRepository struct {
	storageDir string
	mu         sync.RWMutex // Для потокобезопасности при работе с файлами
}

// NewFileRepository создает репозиторий, который пишет в папку storage
func NewFileRepository() GameRepository {
	dir := "storage"
	// Создаем папку, если её нет
	if _, err := os.Stat(dir); os.IsNotExist(err) {
		_ = os.Mkdir(dir, 0755)
	}
	return &fileRepository{storageDir: dir}
}

func (r *fileRepository) SaveGame(game *model.GameDTO) error {
	r.mu.Lock()
	defer r.mu.Unlock()

	// Путь к файлу: storage/uuid.json
	filePath := filepath.Join(r.storageDir, fmt.Sprintf("%s.json", game.ID))

	file, err := os.Create(filePath)
	if err != nil {
		return err
	}
	defer file.Close()

	// Записываем JSON с отступами для читаемости
	encoder := json.NewEncoder(file)
	encoder.SetIndent("", "  ")
	return encoder.Encode(game)
}

func (r *fileRepository) LoadGame(id string) (*model.GameDTO, error) {
	r.mu.RLock()
	defer r.mu.RUnlock()

	filePath := filepath.Join(r.storageDir, fmt.Sprintf("%s.json", id))

	file, err := os.Open(filePath)
	if err != nil {
		return nil, fmt.Errorf("игра не найдена: %w", err)
	}
	defer file.Close()

	var game model.GameDTO
	if err := json.NewDecoder(file).Decode(&game); err != nil {
		return nil, err
	}

	return &game, nil
}
