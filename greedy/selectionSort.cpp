#include<bits/stdc++.h>
using namespace std;

void selectionSort(int *arr,int n){
    int min,temp;
    for(int i=0;i<n;i++){
        min = i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[min]){
                min=j;
            }
        }
        if(min!=i){
            temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }
}

int main(){
    int arr[5] = {2,4,1,3,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    selectionSort(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
    return 0;
}