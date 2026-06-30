package cache

import (
	"container/list"
	"sync"
)

// Cache — структура LRU-кэша
type Cache[T any] struct {
	capacity int
	cache    map[interface{}]*list.Element
	list     *list.List
	mutex    sync.Mutex
}

// item — элемент кэша
type item[T any] struct {
	key   interface{}
	value T
}

// NewCache - конструктор кэша
func NewCache[T any](capacity int) *Cache[T] {
	return &Cache[T]{
		capacity: capacity,
		cache:    make(map[interface{}]*list.Element),
		list:     list.New(),
	}
}

// Set - установка значения в кэш
func (c *Cache[T]) Set(key interface{}, value T) {
	c.mutex.Lock()
	defer c.mutex.Unlock()

	if elem, ok := c.cache[key]; ok {
		elem.Value.(*item[T]).value = value
		c.list.MoveToFront(elem)
		return
	}

	if c.list.Len() >= c.capacity {
		lastElem := c.list.Back()
		if lastElem != nil {
			lastItem := c.list.Remove(lastElem).(*item[T])
			delete(c.cache, lastItem.key)
		}
	}

	newItem := &item[T]{key: key, value: value}
	newElem := c.list.PushFront(newItem)
	c.cache[key] = newElem
}

// Get — возвращает элемент из кэша
func (c *Cache[T]) Get(key interface{}) (T, bool) {
	c.mutex.Lock()
	defer c.mutex.Unlock()

	elem, ok := c.cache[key]
	if !ok {
		var zero T
		return zero, false
	}

	c.list.MoveToFront(elem)
	return elem.Value.(*item[T]).value, true
}

// Clear — очищает кэш
func (c *Cache[T]) Clear() {
	c.mutex.Lock()
	defer c.mutex.Unlock()
	c.cache = make(map[interface{}]*list.Element)
	c.list.Init()
}
