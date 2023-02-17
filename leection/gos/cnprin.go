package main

import (
	"sync"
)

func testchannel(i int, cn chan int, wg *sync.WaitGroup) {
	defer wg.Done()
	if i == 1 {
		cn <- 1
		println("%v", i)
	}
	for inx := range cn {
		inx++
		if inx > 100 {
			println("hello\n")
			//close(cn)
			return
		}
		println("%v ", inx)
		cn <- inx
	}
}
func main() {
	wg := sync.WaitGroup{}
	wg.Add(1)
	cn := make(chan int)
	go testchannel(1, cn, &wg)
	go testchannel(2, cn, &wg)
	wg.Wait()
	return
}
