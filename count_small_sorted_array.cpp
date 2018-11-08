#include<iostream>
#include<vector>
using namespace std;

int binarySearchCount(vector<int>arr, int key)
{   int n=arr.size();
    int left = 0, right = n;
 
    int mid;
    while (left < right)
    {
        mid = left + (right-left)/2;
        if (arr[mid] == key)
        {
            while (arr[mid+1] == key && mid+1<n)
                 mid++;
            break;
        }
        else if (arr[mid] > key)
            right = mid;
        else
            left = mid + 1;
    }
    while (arr[mid] > key)
        mid--;
    return mid + 1;
}

int main(int argc, char const *argv[])
{
    vector<int>v;
    for(int i=1;i<8;i++)
        v.push_back(i);
    cout<<binarySearchCount(v,3);
    return 0;
}