package main

import (
	"fmt"
)

type ListNode struct {
	Value int
	Next  *ListNode
}

func CreateListNode(value int) *ListNode {
	return &ListNode{Value: value}
}

func ConnectListNodes(node1, node2 *ListNode) {
	node1.Next = node2
}

func PrintList(head *ListNode) {
	node := head
	for node != nil {
		fmt.Printf("%d\t", node.Value)
		node = node.Next
	}
	fmt.Println()
}

func PrintListReversinglyIteratively(head *ListNode) {
	var stack []*ListNode
	node := head

	for node != nil {
		stack = append(stack, node)
		node = node.Next
	}

	for len(stack) > 0 {
		node := stack[len(stack)-1]
		stack = stack[:len(stack)-1]
		fmt.Printf("%d\t", node.Value)
	}
	fmt.Println()
}

func PrintListReversinglyRecursively(head *ListNode) {
	if head != nil {
		PrintListReversinglyRecursively(head.Next)
		fmt.Printf("%d\t", head.Value)
	}
	fmt.Println()
}

func Test(head *ListNode) {
	PrintList(head)
	PrintListReversinglyIteratively(head)
	PrintListReversinglyRecursively(head)
}

func Test1() {
	fmt.Println("\nTest begins.")
	node1 := CreateListNode(1)
	node2 := CreateListNode(2)
	node3 := CreateListNode(3)
	node4 := CreateListNode(4)
	node5 := CreateListNode(5)
	ConnectListNodes(node1, node2)
	ConnectListNodes(node2, node3)
	ConnectListNodes(node3, node4)
	ConnectListNodes(node4, node5)
	Test(node1)
}

func main() {
	Test1()
}
