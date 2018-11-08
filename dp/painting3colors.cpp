#include<bits/stdc++.h>
using namespace std;
#define R 3
#define C 3

int ways(int arr[R][C],int r,int c){
    int cost[R][C];
    for(int i=0;i<C;i++){
        cost[0][i] = arr[0][i];
    }
    for(int i=1;i<r;i++){
        cost[i][0] = min(cost[i-1][1],cost[i-1][2]) + arr[i][0];
        cost[i][1] = min(cost[i-1][0],cost[i-1][2]) + arr[i][1];
        cost[i][2] = min(cost[i-1][0],cost[i-1][1]) + arr[i][2];   
    }
    int m = 10000;
    for(int i=0;i<3;i++){
        if(cost[R-1][i]<m)
            m = cost[R-1][i];
    }
    return m;

}


int main(){
    int arr[R][C]={{13,2,10},{10,13,5},{13,4,9}};
    cout<<"No. of ways to paint buildings using 3 colors with no two subsequent building having same color"<<ways(arr,R,C);
    return 0;
}