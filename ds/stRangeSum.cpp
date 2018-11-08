#include<bits/stdc++.h>
using namespace std;

int getMid(int l, int r){
    return l+(r-l)/2;
}

int getSumUtil(int *st,int ss, int se,int qs,int qe,int si){
    if(qs<=ss && qe>=se)
        return st[si];
    if(qs>se || ss>qe)
        return 0;
    
    int mid = getMid(ss,se);
    return getSumUtil(st,ss,mid,qs,qe,2*si+1)+getSumUtil(st,mid+1,se,qs,qe,si*2+2);
}

int getSum(int *st, int n, int qs, int qe)
{
    if (qs < 0 || qe > n-1 || qs > qe)
        return -1;
    return getSumUtil(st, 0, n-1, qs, qe, 0);
}

void updateUtil(int *st,int si,int ss,int se,int diff,int i){
    if(i<ss || i>se)
        return;
    st[si] = st[si] + diff;
    if(ss!=se){
       int mid = getMid(ss, se);
        updateUtil(st,2*si + 1, ss, mid, diff,i );
        updateUtil(st,2*si + 2, mid+1, se, diff,i);
    }
}

void update(int arr[],int *st,int n,int i,int newValue){
    if(i<0 || i>n-1)
        return;
    int diff = newValue - arr[i];
    arr[i] = newValue;
    updateUtil(st,0,0,n-1,diff,i);
}

int constructSTUtil(int arr[], int ss, int se, int *st, int si){
    if(ss==se){
        st[si] = arr[ss];
        return arr[ss];
    }
    int mid = getMid(ss,se);
    st[si] = constructSTUtil(arr,ss,mid,st,2*si+1) + constructSTUtil(arr,mid+1,se,st,si*2+2);
    return st[si];
}

int *constructST(int arr[], int n)
{
    int height = (int)(ceil(log2(n)));
    int max_size = 2* (int)(pow(2,height))-1;
    int *st = new int[max_size];
    constructSTUtil(arr,0,n-1,st,0);
    return st;
}
int main()
{
	int arr[] = {1, 3, 5, 7, 9, 11};
	int n = sizeof(arr)/sizeof(arr[0]);
	int *st = constructST(arr, n);
	printf("Sum of values in given range = %dn", getSum(st, n, 1, 3));
	update(arr, st, n, 1, 10);
	printf("Updated sum of values in given range = %dn",getSum(st, n, 1, 3));
	return 0;
}
