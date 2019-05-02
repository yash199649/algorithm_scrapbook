/*  Find the sum of contiguous sub array within a one d array of numbers which has largest sum */

#include<iostream>
#include<limits>
using namespace std;

// Brute Force
int maxBrute(int *arr, int n){
	int ans=-1,sum;
	for(int i=0;i<n;i++){
		sum = arr[i];
		for(int j=i+1;j<n;j++){
			sum +=arr[j];
			if(sum>ans)
				ans = sum;
		}
	}
	return ans;
}

// Divide and Conquer

int maxDncUtil(int *arr,int low,int mid,int high){
	int sum=0,leftSum=-99999;
	for(int i=mid;i>=low;i--){
		sum+=arr[i];
		if(sum>leftSum)
			leftSum = sum;
	}
	sum=0;
	int rightSum=-99999;
	for(int i=mid+1;i<=high;i++){
		sum+=arr[i];
		if(sum>rightSum)
			rightSum = sum;
	}
	return leftSum+rightSum;
}

int maxDnc(int *arr,int low,int high){
	if(low==high)
		return arr[low];
	else{
		int mid = (low+high)/2;
		int leftSum = maxDnc(arr,low,mid);
		int rightSum = maxDnc(arr,mid+1,high);
		int crossSum = maxDncUtil(arr,low,mid,high);
		if(leftSum>=rightSum && leftSum>=crossSum)
			return leftSum;
		else if(rightSum>=leftSum && rightSum>=crossSum)
			return rightSum;
		else
			return crossSum;
		 
	}
	return 0;
}




//Kadanes Algorithm

int maxSumSubarray(int *arr,int n){
	int maxSoFar;
	int maxEndingHere=0;
	maxSoFar = -999999;
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
	for (int i = 1; i < n; ++i)
	{
		currentMax = max(currentMax,arr[i]+currentMax);
		maxSoFar = max(maxSoFar,currentMax);
	}
	return maxSoFar;
}


/*Recursive Solution : 2 (Two subsequent numbers should not be selected)
	Recursive Formula: M(i) = arr[0] if i=1
							  max(arr[0],arr[1]) ifi=2
							  max(T[i-1],T[i-2]+arr[i]), if i>2

*/

int maxSumSubarray1(int* arr,int n){
	if(n==1)
		return arr[0];
	else if(n==2)
		return max(arr[0],arr[1]);
	else
		return max(maxSumSubarray1(arr,n-3)+arr[n-1],maxSumSubarray1(arr,n-2));
}

int main(int argc, char const *argv[])
{
	int a[]={-1,-2,-3,-4,5,6,7};
	int n=7;
	cout<<"Sum of largest contiguous sub array is :"<<maxDnc(a,0,n);
	return 0;
}