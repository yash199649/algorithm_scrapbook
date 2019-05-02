#include<bits/stdc++.h>
using namespace std;

int getMid(int a,int b){
    return a+(b-a)/2;
}

void updateRangeUtil(int *st,int si,int ss,int se,int qs,int qe,int *lazy,int diff){
    if(lazy[si]!=0){
        st[si] += (se-ss+1)*lazy[si];
        if(ss!=se){
            lazy[2*si+1] +=lazy[si];
            lazy[2*si+2] +=lazy[si];
        }
        lazy[si]=0;
    }
    else{
        if(ss>se || ss>qe || se<qs)
            return;
        if(ss>=qs && se<=qe){
            st[si] +=diff;
        
        if(ss!=se){
            lazy[2*si+1] +=diff;
            lazy[2*si+1] +=diff;
        }
    return;
        
    }
    }
    int mid = getMid(ss,se);
    updateRangeUtil(st,si+2+1,ss,mid,qs,qe,lazy,diff);
    updateRangeUtil(st,si+2+2,mid+1,se,qs,qe,lazy,diff);
    st[si] = st[2*si+1]+st[2*si+2];
}

void updateRange(int *st,int n, int qs, int qe,int *lazy, int diff){
    updateRangeUtil(st,0,0,n-1,qs,qe,lazy,diff);
}

int getSumUtil(int *st,int *lazy, int si,int ss,int se,int qs,int qe){
    if(lazy[si]!=0){
        st[si]+=lazy[si];
        if(ss==se){
            lazy[2*si+1] = lazy[si];
            lazy[2*si+2] = lazy[si];
        }
        lazy[si]=0;
    }
    if (ss>se || ss>qe || se<qs)
        return 0;

    if (ss>=qs && se<=qe)
        return st[si];
    int mid = getMid(ss,se);
    return getSumUtil(st,lazy,2*si+1,ss,mid,qs,qe)+getSumUtil(st,lazy,(si*2)+2,mid+1,se,qs,qe);
}

int getSum(int *st,int n,int qe,int qs,int *lazy){
    if(qs<0 || qe>n-1)
        return -1;
    return getSumUtil(st,lazy,0,0,n-1,qs,qe);
}

int constructSTUtil(int *st,int arr[],int n,int si,int ss,int se){
    if(ss==se){
        st[si] = arr[ss];
        return arr[ss];
    }
    int mid = getMid(ss,se);
    st[si] = constructSTUtil(st,arr,n,2*si+1,ss,mid)+constructSTUtil(st,arr,n,2*si+2,mid+1,se);
    return st[si];
}
int *constructST(int arr[],int n){
    int height = (int)ceil(log2(n));
    int maxSize = (int)2*pow(2,height)-1;
    int *st = new int[maxSize];
    constructSTUtil(st,arr,n,0,0,n-1);
    return st;
}

int main()
{
    int arr[] = {1, 3, 5, 7, 9, 11};
    int n = sizeof(arr)/sizeof(arr[0]);
    int *st = constructST(arr, n);
    int size = sizeof(st)/sizeof(st[0]);
    int *lazy = new int[size];

    for(int i=0;i<size;i++)
        lazy[i]=0;
    printf("Sum of values in given range = %d\n",
           getSum(st,n, 1, 3,lazy));
    updateRange(st,n, 1, 5,lazy,10);
    printf("Updated sum of values in given range = %d\n",
            getSum( st,n, 1, 3,lazy));
    return 0;
}


