package main

import (
	"fmt"
	"math"
)

func main() {
	var t int
	fmt.Scanf("%d", &t)
	for i := 0; i < t; i++ {
		var greenCost, purpleCost int
		fmt.Scanf("%d %d", &greenCost, &purpleCost)

		var n int
		fmt.Scanf("%d", &n)

		var nFirst, nSecond int
		for j := 0; j < n; j++ {
			var f, s int
			fmt.Scanf("%d %d", &f, &s)

			nFirst += f
			nSecond += s
		}

		totalCost := int(math.Min(float64(nFirst*greenCost+nSecond*purpleCost), float64(nFirst*purpleCost+nSecond*greenCost)))
		fmt.Println(totalCost)
	}
}
