package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {

	scanner1 := bufio.NewScanner(os.Stdin)
	var num1 float64

	for {
		fmt.Println("Enter the left operand:")
		scanner1.Scan()
		input1 := scanner1.Text()
		var err1 error
		num1, err1 = strconv.ParseFloat(input1, 64)
		if err1 == nil {
			break
		}

		fmt.Println("Error: Invalid number entered!")
	}

	scanner2 := bufio.NewScanner(os.Stdin)
	var operation string

	for {
		fmt.Println("Enter the mathematical operation (+, -, *, /):")
		scanner2.Scan()
		operation = scanner2.Text()

		switch operation {
		case "+", "-", "*", "/":
		default:
			fmt.Println("Error: Invalid operation!")
			continue
		}
		break
	}

	scanner3 := bufio.NewScanner(os.Stdin)
	var num2 float64
	var result float64

	for {

		for {
			fmt.Println("Enter the right operand:")
			scanner3.Scan()
			input2 := scanner3.Text()

			var err2 error
			num2, err2 = strconv.ParseFloat(input2, 64)
			if err2 == nil {
				break
			}
			fmt.Println("Error: Invalid number entered!")
		}

		switch operation {
		case "+":
			result = num1 + num2
		case "-":
			result = num1 - num2
		case "*":
			result = num1 * num2
		case "/":
			if num2 == 0 {
				fmt.Println("Error: division by zero! Please enter a non-zero number.")
				continue
			}
			result = num1 / num2
		}

		break
	}

	fmt.Printf("Result: %.3f\n", result)
}
