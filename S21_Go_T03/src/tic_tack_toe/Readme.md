## Структура проекта

tic_tac_toe/
├── datasource/
│   ├── model/
│   │   └── game_dto.go          # DTO (Data Transfer Object) для игры
│   └── repository/
│       ├── file_repository.go   # Репозиторий для сохранения игр в файлы
│       ├── in_memory_repository.go # Репозиторий для хранения игр в памяти
│       └── repository.go        # Интерфейс репозитория
├── di/
│   └── container.go             # Контейнер зависимостей (DI)
├── domain/
│   ├── game_service.go          # Логика игры (сервисный слой)
│   ├── interface.go             # Интерфейс сервиса
│   └── models.go                # Доменные модели
├── web/
│   ├── domain_layer.go          # Повторение доменных типов для веб-слоя
│   ├── game_handler.go          # HTTP-хендлеры
│   ├── game_mapper.go           # Мапперы между доменными и DTO-моделями
│   └── game_response.go         # Модели для ответов API
├── main.go                      # Точка входа
└── README.md                    # Документация

## Запуск проекта

```bash
cd src/tic_tac_toe
go run main.go
```

Сервер запускается на `http://localhost:8080`


### Создание игры:
```bash
curl -X POST http://localhost:8080/game
```

### Получение состояния:
```bash
curl http://localhost:8080/game/{game_id}
```

### Выполнение хода:
```bash
curl -X POST http://localhost:8080/game/{game_id} \
  -H "Content-Type: application/json" \
  -d '{
    "id": "{game_id}",
    "board": [
      [1, 0, 0],
      [0, 0, 0],
      [0, 0, 0]
    ],
    "current_player": 2,
    "status": "active"
  }'

```

## Убить процесс
sudo lsof -i :8080

kill -9 {PID}