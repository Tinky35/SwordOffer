package main

import (
	"fmt"
)

func countRange(numbers []int, length, start, end int) int {
	if numbers == nil {
		return 0
	}
	count := 0
	for i := 0; i < length; i++ {
		if numbers[i] >= start && numbers[i] <= end {
			count++
		}
	}
	return count
}

func getDuplication(numbers []int) int {
	if numbers == nil || len(numbers) <= 0 {
		return -1
	}
	start, end := 1, len(numbers)-1
	for end >= start {
		middle := (end-start)/2 + start
		count := countRange(numbers, len(numbers), start, middle)
		if end == start {
			if count > 1 {
				return start
			}
			break
		}
		if count > (middle - start + 1) {
			end = middle
		} else {
			start = middle + 1
		}
	}
	return -1
}

func test(testName string, numbers []int, expected []int) {
	result := getDuplication(numbers)
	for _, expectedDup := range expected {
		if result == expectedDup {
			fmt.Printf("%s passed.\n", testName)
			return
		}
	}
	fmt.Printf("%s FAILED. Got %d, expected one of %v\n", testName, result, expected)
}

func test1() {
	numbers := []int{2, 3, 5, 4, 3, 2, 6, 7}
	duplications := []int{2, 3}
	test("test1", numbers, duplications)
}

func main() {
	test1()
}
