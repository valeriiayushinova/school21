package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strings"
)

type WordCount struct {
	Word  string
	Count int
}

func mostFrequentWords(text string, K int) []string {
	wordsList := strings.Fields(text)
	wordsMap := make(map[string]int)

	for _, word := range wordsList {
		wordsMap[word]++
	}

	wordCounter := make([]WordCount, 0, len(wordsMap))
	for word, count := range wordsMap {
		wordCounter = append(wordCounter, WordCount{word, count})
	}

	sort.Slice(wordCounter, func(i, j int) bool {
		return wordCounter[i].Count > wordCounter[j].Count ||
			(wordCounter[i].Count == wordCounter[j].Count && wordCounter[i].Word < wordCounter[j].Word)
	})

	if K <= 0 || len(wordCounter) == 0 {
		return []string{}
	}

	if K > len(wordCounter) {
		K = len(wordCounter)
	}

	result := make([]string, K)
	for i := 0; i < K; i++ {
		result[i] = wordCounter[i].Word
	}

	return result
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	fmt.Println("Enter the text:")
	scanner.Scan()
	text := scanner.Text()

	var K int
	fmt.Println("Enter the number K:")
	fmt.Scan(&K)

	result := mostFrequentWords(text, K)
	fmt.Println(strings.Join(result, " "))
}
