#include<iostream>
using namespace std;

int partition(int arr[],int low,int high){
    int left = low+1;
    int right = high;
    int pivot = arr[low];
    bool done = false;
    while(!done){
        while(arr[left]<=pivot && left<=right)
            left++;
        while(arr[right]>=pivot && right>=left)
            right--;
        if(left<=right){
            int temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
        }
        else
            done=true;
    }
    int temp = arr[low];
    arr[low] = arr[right];
    arr[right] = temp;

    return right;
}

void quickSort(int arr[],int low,int high){
    if(low>=high)
        return;
    int part = partition(arr,low,high);
    quickSort(arr,low,part-1);
    quickSort(arr,part+1,high);
}

int main(){
    int arr[4]={2,1,3,4};
    quickSort(arr,0,3);
    for(int i=0;i<4;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}