package main

import (
   "fmt"
)

func main() {
    var n int 
    var d int
    _,_ = fmt.Scan(&n)
    _,_ = fmt.Scan(&d)

    arr := make([]int, n)

    for i := 0; i< n; i++ {
        _,_ = fmt.Scan(&arr[i])
    }
    leftrotation(arr, d)
}

func leftrotation(arr []int, d int) {
    l := len(arr)
    arr1 := make([]int, l)

    for i := 0 ; i < l; i++ {
       n := l - d + i
       if n >= l {
          n = n - l
       }
       arr1[n] = arr[i]
    }

    for i:=0; i < len(arr); i++ {
        fmt.Println(arr1[i], " ")
    }
}
