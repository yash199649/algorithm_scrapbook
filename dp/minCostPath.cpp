/*  Given a cost matrix cost[][] and a position (m,n) in 
cost matrix find out the path with minimum cost to the traverse from (0,0) to (m,n)   */

#include<bits/stdc++.h>
using namespace std;
#define R 3
#define C 3
#define f first
#define s second
#define pb push_back
#define pp pop_back
#define mp make_pair
#define ll long long
#define lli long long int
#define ld double
#define ull unsigned long long
#define PI pair < int, int >
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,b) for(i=0;i<b;i++)
#define rep1(i,b) for(i=1;i<=b;i++)
#define pd(n) printf("%d\n",n)
#define pl(n) printf("%lld\n",n)
#define sl(n) scanf("%lld",&n)
#define sd(n) scanf("%d",&n)
#define pn printf("\n")
#define INT_MAX 2147483647
#define INT_MIN -2147483647
const int N = 2050;
const int M = 123;
const ld Pi = acos(-1);
const ll Inf = 1e18;
const int inf = 1e9;
const int mod = 1e9 + 7;
const int Sz = 501;
const int MOD = 1e9 + 7;
void add(int &a, int b) {
  a += b;
  if (a >= mod) a -= mod;
}
int mult(int a, int b) {
  return 1ll * a * b % mod;
}

int min(int a,int b,int c){
  if(a<b && a<c)
    return a;
  else if(b<a && b<c)
    return b;
  else
    return c;
}

int minPath(int cost[R][C],int i,int j){
  cout<<i<<" "<<j<<endl;
  if(i==0 && j==0)
    return cost[0][0];
  else if(i<0 || j<0)
    return INT_MAX;
  else
    return cost[i][j]+min(minPath(cost,i-1,j),minPath(cost,i,j-1),minPath(cost,i-1,j-1));
  
}

int minPathDp(int cost[R][C],int m,int n){
  int dp[R][C],i,j;
  rep(i,R){
    rep(j,C){
      dp[i][j]=0;
    }
  }
  rep(i,R){
    rep(j,C){
      if(i==0)
        dp[i][j]=cost[i][j]+dp[i][j-1];
      else if(j==0)
        dp[i][j]=cost[i][j]+dp[i-1][j];
    else{
      dp[i][j]=cost[i][j]+min(dp[i-1][j],dp[i][j-1],dp[i-1][j-1]);
    }
  }
    }

    rep(i,R){
    rep(j,C){
      cout<<dp[i][j]<<" ";
    }
    cout<<endl;
  }


    return dp[m][n];

}



int main(int argc, char const *argv[])
{
	 int arr[3][3]={{1,2,3},{4,8,2},{1,5,3}};
   cout<<minPathDp(arr,2,2);

	return 0;
}