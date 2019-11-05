package main

import "fmt"


func main() {
   a := []int{1,2,3,4}

   l := len(a)

   b := make([]int, l)
   j := 0

   for i := l-1 ; i >=0 ; i-- {
       b[j] = a[i]
       j++
   }

   for i := 0; i< l; i++ {
      fmt.Println(b[i])
   }
}
