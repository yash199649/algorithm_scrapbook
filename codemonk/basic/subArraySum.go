package main;
import (
	"fmt"
)

func findSubArrayWithSum(a []int,s int){

}

func main(){
	var t int;
	fmt.Scanf("%d",&t);
	for i:=0; i<t; i++{
		var n,s int;
		fmt.Scanf("%d %d", &n, &s);
		a := make([]int, n)
		for j:=0; j<n; j++{
			fmt.Scanf("%d",&a[j]);
		}
		fmt.Println(findSubArrayWithSum(a,s));

	}

}
