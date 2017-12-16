/*  Given a value n if we want to make change for n cents and we have infinite supply of
 S={S1,S2,S3....} valued coins, how many ways can we make the change   */

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

int trials(int *S,int n,int k){
  
  
}

int trialsDp(int cost[R][C],int m,int n){
  
}



int main(int argc, char const *argv[])
{
	 int arr[3][3]={{1,2,3},{4,8,2},{1,5,3}};
   cout<<minPathDp(arr,2,2);

	return 0;
}