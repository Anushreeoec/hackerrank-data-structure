package main

import (
   "fmt"
   "bufio"
   "io"
   "os"
   "strings"
)

func main () {
   var n int

   _,_ = fmt.Scan(&n)

   var strings []string

    reader := bufio.NewReaderSize(os.Stdin, 1024 * 1024)

    for i := 0; i < int(n); i++ {
        stringsItem := readLine(reader)
        strings = append(strings, stringsItem)
    }

    var q int

    _,_ = fmt.Scan(&q)

    var queries []string

    for i := 0; i < int(q); i++ {
        queriesItem := readLine(reader)
        queries = append(queries, queriesItem)
    }

    res := matchingStrings(strings, queries)

    fmt.Println(res)
}

func readLine(reader *bufio.Reader) string {
    str, _, err := reader.ReadLine()
    if err == io.EOF {
        return ""
    }

    return strings.TrimRight(string(str), "\r\n")
}

func matchingStrings(strings []string, queries []string)  []int32 {
    var res []int32
    for _, q := range queries {
      var i int32
      for _, s := range strings {
         if q == s {
            i++
         }
      }
      res = append(res, i)
   }
   return res
}
