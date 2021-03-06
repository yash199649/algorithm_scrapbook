/*  Gicen a binary matrix find out he maximum size square matrix with all ones */

#include<bits/stdc++.h>
using namespace std;
#define R 6
#define C 5
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

int subMatrixSize(int  arr[R][C]){
  int dp[R][C],i,j,max=INT_MIN;
  rep(i,R)
  {
    dp[i][0]=arr[i][0];
  }
  rep(i,C)
  {
    dp[0][i]=arr[0][i];
  }

  REP(i,1,R){
    REP(j,1,C){
      if (arr[i][j]==1)
        dp[i][j]=min(dp[i-1][j],dp[i][j-1],dp[i-1][j-1])+1;
      else
        dp[i][j]=0;
    }
  }
  rep(i,R){
    rep(j,C){
      if(max<dp[i][j])
        max=dp[i][j];
    }
  }

  return max;
}



int main(int argc, char const *argv[])
{
	 int M[R][C] =  {{0, 1, 1, 0, 1}, 
                   {1, 1, 0, 1, 0}, 
                   {0, 1, 1, 1, 0},
                   {1, 1, 1, 1, 0},
                   {1, 1, 1, 1, 1},
                   {0, 0, 0, 0, 0}};
               
  cout<<subMatrixSize(M);

	return 0;
}