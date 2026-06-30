package main

import (
	"bufio"
	"fmt"
	"os"
	"time"
)

type Visit struct {
	Specialization string
	Date           string
}

type PatientHistory map[string][]Visit

type PatientNotFoundError struct{}

func (e *PatientNotFoundError) Error() string {
	return "Patient not found"
}

func main() {
	history := make(PatientHistory)
	scanner := bufio.NewScanner(os.Stdin)

	for {
		fmt.Println("Введите команду (Save, GetHistory, GetLastVisit):")
		if !scanner.Scan() {
			break
		}

		command := scanner.Text()

		switch command {
		case "Save":
			fmt.Println("Введите ФИО пациента:")
			scanner.Scan()
			fullName := scanner.Text()

			fmt.Println("Введите специализацию врача:")
			scanner.Scan()
			specialization := scanner.Text()

			fmt.Println("Введите дату визита (YYYY-MM-DD):")
			scanner.Scan()
			date := scanner.Text()

			if _, err := time.Parse("2006-01-02", date); err != nil {
				fmt.Println("Ошибка: неверный формат даты. Используйте формат YYYY-MM-DD.")
				continue
			}

			visit := Visit{Specialization: specialization, Date: date}
			history[fullName] = append(history[fullName], visit)
			fmt.Println("Данные сохранены.")

		case "GetHistory":
			fmt.Println("Введите ФИО пациента:")
			scanner.Scan()
			fullName := scanner.Text()

			visits, exists := history[fullName]
			if !exists {
				fmt.Println(&PatientNotFoundError{})
				continue
			}

			fmt.Println("История посещений:")
			for _, visit := range visits {
				fmt.Printf("%s %s\n", visit.Specialization, visit.Date)
			}

		case "GetLastVisit":
			fmt.Println("Введите ФИО пациента:")
			scanner.Scan()
			fullName := scanner.Text()

			fmt.Println("Введите специализацию врача:")
			scanner.Scan()
			specialization := scanner.Text()

			visits, exists := history[fullName]
			if !exists {
				fmt.Println(&PatientNotFoundError{})
				continue
			}

			var lastVisitDate string
			found := false

			for _, visit := range visits {
				if visit.Specialization == specialization {
					lastVisitDate = visit.Date
					found = true
				}
			}

			if !found {
				fmt.Println("Визитов к данному специалисту не найдено.")
				continue
			}

			fmt.Println("Дата последнего визита:", lastVisitDate)

		default:
			fmt.Println("Неизвестная команда.")
		}
	}
}
