package main

import "fmt"

func swap(x, y string) (string, string) {
	return y, x
}
func main() {
	if a := 1; a != 0 {
		a, b := swap("aaaaa", "bbbbbb")
		fmt.Println(a, b)
	}
}
