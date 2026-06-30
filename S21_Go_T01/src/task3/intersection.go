package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	firstList, err := readIntList()
	if err != nil {
		fmt.Println("Invalid input")
		return
	}

	secondList, err := readIntList()
	if err != nil {
		fmt.Println("Invalid input")
		return
	}

	intersection := findIntersection(firstList, secondList)

	if len(intersection) == 0 {
		fmt.Println("Empty intersection")
	} else {
		for i, num := range intersection {
			if i > 0 {
				fmt.Print(" ")
			}
			fmt.Print(num)
		}
		fmt.Println()
	}
}

func readIntList() ([]int, error) {
	reader := bufio.NewReader(os.Stdin)
	line, err := reader.ReadString('\n')
	if err != nil {
		return nil, err
	}

	line = strings.TrimSpace(line)
	if line == "" {
		return []int{}, nil
	}

	parts := strings.Fields(line)
	var result []int

	for _, part := range parts {
		num, err := strconv.Atoi(part)
		if err != nil {
			return nil, fmt.Errorf("Invalid input")
		}
		result = append(result, num)
	}

	return result, nil
}

func findIntersection(first, second []int) []int {
	secondSet := make(map[int]bool)
	for _, num := range second {
		secondSet[num] = true
	}

	var intersection []int
	seen := make(map[int]bool)

	for _, num := range first {
		if secondSet[num] && !seen[num] {
			intersection = append(intersection, num)
			seen[num] = true
		}
	}

	return intersection
}
