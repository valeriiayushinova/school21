package main

import (
	"flag"
	"fmt"
	"math/rand"
	"sync"
	"time"
)

type Result struct {
	Number   int
	Duration int
}

func main() {
	var N, M int

	flag.IntVar(&N, "N", 0, "number of goroutines")
	flag.IntVar(&M, "M", 0, "number of milliseconds")

	flag.Parse()

	rand.Seed(time.Now().UnixNano())

	results := make([]Result, N)

	var wg sync.WaitGroup

	var mu sync.Mutex

	for i := 0; i < N; i++ {
		wg.Add(1)
		go func(num int) {
			defer wg.Done()
			sleepTime := rand.Intn(M + 1)
			time.Sleep(time.Duration(sleepTime) * time.Millisecond)

			mu.Lock()
			results[num] = Result{num, sleepTime}
			mu.Unlock()
		}(i)
	}

	wg.Wait()

	for i := 0; i < N; i++ {
		for j := i + 1; j < N; j++ {
			if results[i].Duration < results[j].Duration {
				results[i], results[j] = results[j], results[i]
			}
		}
	}

	for _, result := range results {
		fmt.Printf("<%d, %d>\n", result.Number, result.Duration)
	}
}
