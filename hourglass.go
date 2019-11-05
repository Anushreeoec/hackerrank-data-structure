package main

import (
   "fmt"
   "bufio"
   "os"
   "strings"
   "io"
   "strconv"
)

func main() {
    reader := bufio.NewReaderSize(os.Stdin, 1024 * 1024)

    var arr [][]int32
    for i := 0; i < 6; i++ {
        arrRowTemp := strings.Split(readLine(reader), " ")

        var arrRow []int32
        for _, arrRowItem := range arrRowTemp {
            arrItemTemp, err := strconv.ParseInt(arrRowItem, 10, 64)
            if err!= nil {
            fmt.Println(err)
            }
            arrItem := int32(arrItemTemp)
            arrRow = append(arrRow, arrItem)
        }

        if len(arrRow) != int(6) {
            panic("Bad input")
        }

        arr = append(arr, arrRow)
    }

    result := hourglassSum(arr)

    fmt.Println(result)
}

func readLine(reader *bufio.Reader) string {
    str, _, err := reader.ReadLine()
    if err == io.EOF {
        return ""
    }

    return strings.TrimRight(string(str), "\r\n")
}


func hourglassSum(arr [][]int32) int32 {
    var max int32
    max = -100

   for i := 0; i < 4; i++ {
       for j := 0; j < 4; j++ {
           sum := arr[i][j] + arr[i][j+1] + arr[i][j+2] + arr[i+1][j+1] + arr[i+2][j] + arr[i+2][j+1]+arr[i+2][j+2]
            if sum > max {
                max = sum
            }
       }
   }

   return max

}
