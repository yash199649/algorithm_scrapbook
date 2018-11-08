#include<bits/stdc++.h>
using namespace std;

// Problem Reducible to maxSumSubarray

/*
    Recursive Function:
    T(i) = A[1] if i=1
         = max(A[1],A[2]) if i=2
         = max(T[i-2]+A[i],T[i-1])

*/

int maxSum(vector<int> v){
    int n = v.size();
    vector<int> dp(n+1,0);
    dp[0]=v[0];
    dp[1] = max(v[0],v[1]);
    for(int i=2;i<n;i++){
        dp[i] = max(dp[i-2]+v[i],dp[i-1]);
    }
    return dp[n-1];
}

int main(){
    vector<int> v;
    v.push_back(-2);
    v.push_back(3);
    v.push_back(-16);
    v.push_back(100);
    v.push_back(-4);
    v.push_back(5);
    cout<<"Max amount of money that can ve stealed without alerting the police: "<<maxSum(v)<<endl;

    return 0;
}