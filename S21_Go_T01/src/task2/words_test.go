package main

import (
	"reflect"
	"testing"
)

func TestMostFrequentWords(t *testing.T) {
	tests := []struct {
		name     string
		words    string
		K        int
		expected []string
	}{
		{
			name:     "Normal behavior, K < number of unique words",
			words:    "aa bb cc aa cc cc cc aa ab ac bb",
			K:        3,
			expected: []string{"cc", "aa", "bb"},
		},
		{
			name:     "Normal behavior, K = 0",
			words:    "aa bb cc aa cc cc cc aa ab ac bb",
			K:        0,
			expected: []string{},
		},
		{
			name:     "Empty list",
			words:    "",
			K:        3,
			expected: []string{},
		},
		{
			name:     "Input list contains fewer unique words than K",
			words:    "aa bb cc aa cc cc cc aa ab ac bb",
			K:        13,
			expected: []string{"cc", "aa", "bb", "ab", "ac"},
		},
		{
			name:     "Same frequency, sorted by lexicographic order",
			words:    "bb cc aa cc bb cc aa bb aa ac bc",
			K:        3,
			expected: []string{"aa", "bb", "cc"},
		},
	}

	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			result := mostFrequentWords(tt.words, tt.K)
			if !reflect.DeepEqual(result, tt.expected) {
				t.Errorf("Ожидалось %v, получено %v", tt.expected, result)
			}
		})
	}
}
