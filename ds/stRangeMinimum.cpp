#include<bits/stdc++.h>
using namespace std;

int getMid(int a,int b){
    return a+(b-a)/2;
}

int min(int a,int b){
    return a>b?b:a;
}

int getMinUtil(int *st,int si,int ss,int se,int qs,int qe){
    if(qs<=ss && qe>=se)
        return st[si];
    if(qs>se || qe<ss)
        return 99999;
    int mid = getMid(ss,se);

    return min(getMinUtil(st,2*si+1,ss,mid,qs,qe),getMinUtil(st,2*si+2,mid+1,se,qs,qe));
}

int getMin(int *st,int n,int qs,int qe){
    if(qs<0 || qe>n-1)
        return -1;
    return getMinUtil(st,0,0,n-1,qs,qe);
}

int constructSTUtil(int arr[],int *st,int si,int ss,int se ){
    if(ss==se){
        st[si] = arr[se];
        return arr[se];
    }
    int mid = getMid(ss,se);
    st[si] = min(constructSTUtil(arr,st,2*si+1,ss,mid),constructSTUtil(arr,st,2*si+2,mid+1,se));
    return st[si];
}

int *constructST(int arr[],int n){
    int height = (int)ceil(log2(n));
    int maxSize = (int)(2*pow(2,height)-1);
    int *st = new int[maxSize];
    constructSTUtil(arr,st,0,0,n-1);
    return st;
}
int main()
{
    int arr[] = {1, 3, 2, 7, 9, 11};
    int n = sizeof(arr)/sizeof(arr[0]);
    int *st = constructST(arr, n);
    int qs = 1;  
    int qe = 5;  
    printf("Minimum of values in range [%d, %d] is = %d\n",
                           qs, qe, getMin(st, n, qs, qe));
 
    return 0;
}