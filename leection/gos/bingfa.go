package main

import (
    "fmt"
	"time"
	"sync"
)

func fun(ch chan int,rv chan int,wg *sync.WaitGroup){
	defer wg.Done()
    for  _ = range rv{
		j:=1
		for i:=range ch{
			fmt.Println(i);
			j++
			if j == 11 {
				break
			}
		}
		fmt.Println("\n")
	}
}
func main() {
    ch:=make(chan int,10)
	rv:=make(chan int)
	wg :=sync.WaitGroup{}
	wg.Add(1);
    go fun(ch,rv,&wg);
    for i:=0;i<1000;{
        for j:=0;j<10;j++{
        	ch<-i
			i++
        }
		rv<-1
        time.Sleep(time.Millisecond*500)
    }
	close(rv)
	wg.Wait()
}