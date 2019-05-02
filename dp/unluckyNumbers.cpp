#include<iostream>
using namespace std;

int count(int n){
    if(n==0)
        return 0;
    else if(n==1)
        return 1;
    else {
        return 10*count(n-1)-count(n-2);
    }
}

// DP tabulation

int dpCount(int n){
    int dp[n+1];
    dp[0]=0;
    dp[1]=1;
    for(int i=2;i<=n;i++){
        dp[i] = 10*dp[i-1]-dp[i-2];
    }
    return dp[n];
}

int main(){
    cout<<"No. of unlucky 3 digit numbers :"<<dpCount(3);
    return 0;
}