package main

import (
    "fmt"
    "strings"
    "strconv"
    "os"
    "bufio"
    "io"
)

func main () {
   var n int32
   var m int32

   _, _ = fmt.Scan(&n)
   _, _ = fmt.Scan(&m)
   reader := bufio.NewReaderSize(os.Stdin, 1024 * 1024)
   var queries [][]int32
   for i:= 0; i< int(m); i++ {
     queriesRowTemp := strings.Split(readLine(reader), " ")

      var queriesRow []int32
      for _, queriesRowItem := range queriesRowTemp {
          queriesItemTemp, err := strconv.ParseInt(queriesRowItem, 10, 64)
          if err != nil {
              fmt.Println("error : ",err)
          }
          queriesItem := int32(queriesItemTemp)
          queriesRow = append(queriesRow, queriesItem)
      }

      queries = append(queries, queriesRow)

   }
   result := arrayManipulation(n, queries)

   fmt.Println(result)
}

func readLine(reader *bufio.Reader) string {
    str, _, err := reader.ReadLine()
    if err == io.EOF {
        return ""
    }

    return strings.TrimRight(string(str), "\r\n")
}

func arrayManipulation(n int32, queries [][]int32) int64 {
    m := len(queries)
    n1 := int(n)
    l := n1+1
    x := 0

    arr := make([]int, l)
    max := x

    for _, query := range queries {
        a := int(query[0])
        b := int(query[1])
        k := int(query[2])

        arr[a] = arr[a] + k
        if b+1 <= n1 {
           arr[b+1] = arr[b+1] - k
        }
    }

    for i:=0 ; i<= n1; i++ {
        x = x+arr[i]
        if max < x {
            max = x
        }
    }
    maxstr := fmt.Sprint(max)
    max64, _ := strconv.ParseInt(maxstr, 10, 64)
    return max64
}
