#include <iostream>
using namespace std;
void reverseArray(int* arr,int start,int end){
	int temp;
	while(start<end){
		temp = arr[start];
		arr[start] = arr[end];
		arr[end] = temp;
		start++;
		end--;
	}
}


void leftRotate(int* arr,int d, int n){
	reverseArray(arr,0,d-1);
	reverseArray(arr,d,n-1);
	reverseArray(arr,0,n-1);
}

void rightRotate(int* arr,int d,int n){
	leftRotate(arr,n-d,n);
}

void printArray(int* arr,int n){
	for (int i = 0; i < n; i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int *arr;
	for (int i = 0; i < n; ++i)
	{
		cin>>arr[i];
	}

	printArray(arr,n);

	leftRotate(arr,2,n);
	// Here 2 stands for number of rotations
	printArray(arr,n);
	rightRotate(arr,2,n);
	printArray(arr,n);



	return 0;
}