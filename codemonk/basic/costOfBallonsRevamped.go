package main;

import (
	"fmt"
	"math"
)

func main(){
	var t int;
	fmt.Scanf("%d", &t)
	for i:=0; i<t; i++ {
		fmt.Println(i);
		var a,b,c int;
		fmt.Scanf("%d %d", &a, &b);
		fmt.Scanf("%d", &c);
		var nFirst, nSecond int;
		for j:=0; j<c; j++ {
			var f,g int;
			fmt.Scanf("%d %d",&f,&g);
			nFirst += f;
			nSecond +=g;
		}
		totalCost := int(math.Min(float64(nFirst*a+nSecond*b), float64(nFirst*b+nSecond*a)))
		fmt.Println(totalCost)
	}

}
