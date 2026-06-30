package main

type Cache[T any] struct {
	capacity int
	elem     []T
}

func NewCache[T any](capacity int) *Cache[T] {
	return &Cache[T]{
		capacity: capacity,
		elem:     make([]T, 0, capacity),
	}
}

func (c *Cache[T]) Set(key T) {
	c.elem = append(c.elem, key)
	if len(c.elem) > c.capacity {
		c.elem = c.elem[1:]
	}
}

func (c *Cache[T]) Get(key T) bool {
	for _, v := range c.elem {
		if v == key {
			return true
		}
	}
	return false
}
