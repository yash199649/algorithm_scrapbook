/*  Find nth number in fibonacci sequence  */

#include<bits/stdc++.h>
using namespace std;

// Basic recursion
int fib1(int n){
	if(n<=1)
		return n;
	return fib1(n-1)+fib1(n-2);
}

// Dynamic programming approach
int fib2(int n){
	int f[n+1];
	f[0]=0;
	f[1]=1;
	for (int i = 2; i <=n; ++i)
	{
		f[i]=f[i-1]+f[i-2];
	}

	return f[n];
}

// Space optimized approach
int fib3(int n){
	int a=0,b=1,c;
	if (n==0)
	{
		return a;
	}
	for(int i=2;i<=n;i++){
		c=a+b;
		a=b;
		b=c;
	}
	return b;
}

int main(int argc, char const *argv[])
{
	int n;
	cout<<"Enter the index:";
	cin>>n;
	cout<<"Fibonacci number at index n is :"<<fib1(n)<<fib2(n)<<fib3(n);
	return 0;
}