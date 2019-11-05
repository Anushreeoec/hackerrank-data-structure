package main

import (
   "fmt"
)


type SinglyLLNode struct {
    data int32
    next *SinglyLLNode
}

type SinglyLinkedList struct {
    head *SinglyLLNode
    tail *SinglyLLNode
}

func main () {
    fmt.Println("Input the number of elements in Linked List")
    var n int
    _, _ = fmt.Scan(&n)

    llist := SinglyLinkedList{}

    for i := 0; i < n; i++ {
        var data int32
        _,_ = fmt.Scan(&data)
        llist.InsertNode(data)
    }

    printLinkedList(llist.head)
}


func (llist *SinglyLinkedList) InsertNode (nodeData int32) {
     node := &SinglyLLNode {
         next : nil,
         data : nodeData,
     }

     if llist.head == nil {
         llist.head = node
     } else {
         llist.tail.next = node
     }

     llist.tail = node
}


func printLinkedList (head *SinglyLLNode) {
    node1 := head
    for node1 != nil {
        fmt.Println(node1.data)
        node1 = findNext(node1)
    }
}

func findNext (node *SinglyLLNode) (*SinglyLLNode) {
    node1 := node.next
    return node1
}


