package main

import (
	"flag"
	"fmt"
	"os"
	"os/signal"
	"syscall"
	"time"
)

func runTicker(K uint, tickerChan chan<- string, doneChan <-chan struct{}) {
	i := 1
	startTime := time.Now()
	for {
		select {
		case <-doneChan:
			return
		default:
			time.Sleep(time.Duration(K) * time.Second)
			elapsed := uint64(time.Since(startTime).Seconds())
			tickerChan <- fmt.Sprintf("Tick <%d> since <%d>", i, elapsed)
			i++
		}
	}
}

func handleSignals() <-chan os.Signal {
	signalChan := make(chan os.Signal, 1)
	signal.Notify(signalChan, syscall.SIGTERM, syscall.SIGINT)
	return signalChan
}

func printTicks(tickerChan <-chan string, signalChan <-chan os.Signal, doneChan chan<- struct{}) {
	for {
		select {
		case msg := <-tickerChan:
			fmt.Println(msg)
		case <-signalChan:
			fmt.Println("\nTermination")
			close(doneChan)
			return
		}
	}
}

func main() {
	var K uint
	flag.UintVar(&K, "K", 0, "interval in seconds")
	flag.Parse()

	tickerChan := make(chan string)
	doneChan := make(chan struct{})

	go runTicker(K, tickerChan, doneChan)

	signalChan := handleSignals()

	printTicks(tickerChan, signalChan, doneChan)
}
