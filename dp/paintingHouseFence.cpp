#include<bits/stdc++.h>
using namespace std;

// Recurrence Relation : T[i] = (k-1)*(T[i-1]+T[i-2])

int ways(int n,int k){
    if(n==0)
        return 0;
    else if(n==1)
        return k;
    else if(n==2)
        return k*k;
    int a,b,c;
    a = k;
    b=k*k;
    for(int i=3;i<n;i++){
        c = (k-1)*(a+b);
        a = b;
        b=c;
    }
    return c;
}

int main(){
    int n = 3,k=4;
    cout<<"No. of ways to paint n fences with k colors :"<<ways(n,k);
    return 0;
}