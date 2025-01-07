package main

import (
	"fmt"
)

func coutVec(data []int) {
	for j := 0; j < len(data); j++ {
		if j > 0 {
			fmt.Print("\t")
		}
		fmt.Print(data[j])
	}
	fmt.Println()
}

func repeatNumFun() {
	data := []int{2, 3, 1, 0, 2, 5, 3}
	dataSize := len(data)
	repeatNum := []int{}
	for i := 0; i < dataSize; {
		value := data[i]
		if i == value {
			i++
		} else {
			temp := data[value]
			if value == temp {
				repeatNum = append(repeatNum, value)
				i++
			} else {
				data[value] = value
				data[i] = temp
			}
		}
	}
	coutVec(repeatNum)
}

func main() {
	repeatNumFun()
}
