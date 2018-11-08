#include<iostream>
#include<vector>
using namespace std;

// Recursive solution
int ways(int n){
    if(n==0)
        return 0;
    else if(n==1)
        return 1;
    else if(n==2)
        return 2;
    return ways(n-1)+ways(n-2)+ways(n-3);
}

// using bottom-up approach
int Dpways(int n){
    // vector<int>dp(n+1,0);
    int a=0,b=1,c=2,d;
    for(int i=3;i<=n;i++){
        d=a+b+c;
        a=b;
        b=c;
        c=d;
    }
    return c;
}

int main(){
    int a;
    cout<<"Enter the number of steps: ";
    cin>>a;
    cout<<"No. of ways to jump n steps are :"<<Dpways(a)<<endl;
    return 0;
}