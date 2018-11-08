#include<bits/stdc++.h>
using namespace std;

void merge(int arr[],int low,int mid,int high){
    int n1 = mid-low+1;
    int n2 = high-mid;
    int left[n1],right[n2];

    for(int i=0;i<n1;i++)
        left[i] = arr[low+i];

    for(int i=0;i<n2;i++)
        right[i] = arr[mid+i+1];
    
    int i=0,j=0,k=low;
    while (i < n1 && j < n2)
    {
        if (left[i] <= right[j])
        {
            arr[k] = left[i];
            i++;
        }
        else
        {
            arr[k] = right[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = left[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = right[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[],int l,int r){
    if (l < r)
    {
        int m = l+(r-l)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}

int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7};
    int arr_size = sizeof(arr)/sizeof(arr[0]);
    mergeSort(arr, 0, arr_size - 1);
    for(int i=0;i<arr_size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
    return 0;
}