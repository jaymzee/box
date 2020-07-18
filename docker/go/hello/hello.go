package main
 
import "fmt"

func main() {
    msg := "Hello, World!"
    var x float64 = 3.14
    a := [5]int{4,5,6,7};
    s := []int{1,2,3,4,5}
    fmt.Println(msg);
    fmt.Printf("x = %f\n", x)
    fmt.Println(a)
    fmt.Println(s)

    for i := 0; i < len(s); i++ {
            fmt.Println(s[i])
    }

    for i, v := range s {
            fmt.Printf("%d %d\n", i, v);
    }
}
