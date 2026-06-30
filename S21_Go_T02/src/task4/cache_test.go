package cache

import (
	"sync"
	"testing"
)

func TestCache(t *testing.T) {
	cache := NewCache[int](2)

	// Тест 1: Добавление и получение элементов
	cache.Set("one", 1)
	cache.Set("two", 2)

	value, ok := cache.Get("one")
	if !ok || value != 1 {
		t.Errorf("Expected value 1, got %v", value)
	}

	// Тест 2: Удаление наименее недавно использованного элемента
	cache.Set("three", 3)
	_, ok = cache.Get("two")
	if ok {
		t.Error("Expected 'two' to be evicted")
	}

	// Тест 3: Обновление элемента
	cache.Set("one", 10)
	value, ok = cache.Get("one")
	if !ok || value != 10 {
		t.Errorf("Expected value 10, got %v", value)
	}

	// Тест 4: Очистка кэша
	cache.Clear()
	_, ok = cache.Get("one")
	if ok {
		t.Error("Expected cache to be empty after Clear")
	}
}

func TestConcurrentAccess(t *testing.T) {
	cache := NewCache[int](10)
	var wg sync.WaitGroup

	// Параллельное добавление элементов
	for i := 0; i < 100; i++ {
		wg.Add(1)
		go func(i int) {
			defer wg.Done()
			cache.Set(i, i)
		}(i)
	}

	// Параллельное получение элементов
	for i := 0; i < 100; i++ {
		wg.Add(1)
		go func(i int) {
			defer wg.Done()
			cache.Get(i)
		}(i)
	}

	wg.Wait()
}
