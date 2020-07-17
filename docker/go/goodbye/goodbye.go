package main;
 
import (
	"fmt"
)

type TZ int

const (
	UTC TZ = 0 * 60 * 60
	EST TZ = -5 * 60 * 60
)

var weekend = []string{ "Saturday", "Sunday" }
var timeZone = map[string]TZ{ "UTC":UTC, "EST":EST }

func main() {
	fmt.Println("timeZone:", timeZone)
	fmt.Println("weekend:", weekend)
	fmt.Println("map:", timeZone["apple"])
}