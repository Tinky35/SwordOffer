package main

import (
	"fmt"
)

func Find(matrix [][]int, number int) bool {
	if len(matrix) == 0 || len(matrix[0]) == 0 {
		return false
	}
	rows := len(matrix)
	columns := len(matrix[0])
	row := 0
	column := columns - 1
	for row < rows && column >= 0 {
		current := matrix[row][column]
		if current == number {
			return true
		} else if current > number {
			column--
		} else {
			row++
		}
	}
	return false
}

func Test(testName string, matrix [][]int, number int, expected bool) {
	result := Find(matrix, number)
	if result == expected {
		fmt.Printf("%s: Passed.\n", testName)
	} else {
		fmt.Printf("%s: Failed.\n", testName)
	}
}

func main() {
	matrix := [][]int{
		{1, 2, 8, 9},
		{2, 4, 9, 12},
		{4, 7, 10, 13},
		{6, 8, 11, 15},
	}
	Test("Test1", matrix, 7, true)
}
