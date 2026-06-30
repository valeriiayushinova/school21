package main

import (
	"flag"
	"fmt"
)

func generator(K, N int) <-chan int {
	ch1 := make(chan int)

	go func() {
		defer close(ch1)

		for i := K; i <= N; i++ {
			ch1 <- i
		}
	}()
	return ch1
}

func square(ch1 <-chan int) <-chan int {
	ch2 := make(chan int)

	go func() {
		defer close(ch2)

		for i := range ch1 {
			ch2 <- i * i
		}
	}()
	return ch2
}

func main() {
	var K, N int
	flag.IntVar(&K, "K", 0, "number from")
	flag.IntVar(&N, "N", 0, "number to")

	flag.Parse()

	ch1 := generator(K, N)
	ch2 := square(ch1)

	for squared := range ch2 {
		fmt.Println(squared)
	}
}
