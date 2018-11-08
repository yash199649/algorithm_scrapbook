#include<iostream>
using namespace std;

void heapify(int *arr,int n, int i){
    int largest = i;
    int left = 2*i+1;
    int right = 2*i+2;
    if(left<n && arr[left]>arr[largest])
        largest = left;
    if(right<n && arr[right]>arr[largest])
        largest = right;
    if(largest!=i){
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest]= temp;
        heapify(arr,n,largest);   
    }
}

void heapSort(int arr[],int n){
    for(int i=(n/2)-1;i>=0;i--){
        heapify(arr,n,i);
    }
    for(int i=n-1;i>=0;i--){
        swap(arr[i],arr[0]);
        heapify(arr,n,0);
    }

}

void printArray(int arr[], int n)
{
    for (int i=0; i<n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}


int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr)/sizeof(arr[0]);
 
    heapSort(arr, n);
 
    cout << "Sorted array is \n";
    printArray(arr, n);
}

