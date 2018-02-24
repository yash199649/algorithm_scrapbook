/*  Given a string str of digits and an integer n, build the lowest possible number 
by removing n digits from the string and not changing the order of input digits. */

#include<bits/stdc++.h>
using namespace std;

//Kadanes Algorithm

int maxSumSubarray(int *arr,int n){
	int maxSoFar=INT_MIN,maxEndingHere=0;
	for (int i = 0; i < n; ++i)
	{
		maxEndingHere = maxEndingHere + arr[i];
		if(maxEndingHere>maxSoFar)
			maxSoFar=maxEndingHere;

		if(maxEndingHere<0)
			maxEndingHere=0;
		
	}

	return maxSoFar;
}

// dp approach
int maxSumSubarrayDp(int *arr,int n){
	int maxSoFar=arr[0];
	int currentMax = arr[0];
	for (int i = 0; i < n; ++i)
	{
		currentMax = max(currentMax,arr[i]+currentMax);
		maxSoFar = max(maxSoFar,currentMax);
	}
	return maxSoFar;
}


int main(int argc, char const *argv[])
{
	int a[]={-1,-2,-3,-4,5,6,7};
	int n=7;
	cout<<"Sum of largest contiguous sub array is :"<<maxSumSubarray(a,n);
	return 0;
}