#include<iostream>
using namespace std;

// recursive approach
int change(int S[],int m,int n){
	if(n==0)
		return 1;
	if(n<0)
		return 0;
	if(m<=0 && n>=1)
		return 0;

	return change(S,m-1,n) + change(S,m,n-S[m-1]); 
}

// dp approach

int changeDp(int S[],int m,int n){
	int table[n+1];
    memset(table, 0, sizeof(table));
    table[0] = 1;
    for(int i=0; i<m; i++)
        for(int j=S[i]; j<=n; j++)
            table[j] += table[j-S[i]];
    return table[n];
}


int main(int argc, char const *argv[])
{
	int i, j;
    int arr[] = {1, 2, 3};
    int m = sizeof(arr)/sizeof(arr[0]);
    printf("%d ", changeDp(arr, m, 4));
	return 0;
}