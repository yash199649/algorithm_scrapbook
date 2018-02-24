/*  Given an array of integers find the length of largest increasing subsequence */

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

int lisDp(int *arr,int n){
  int lis[n];
  if(n==1)
    return 1;
  if(n==2){
    if(arr[1]>arr[0])
      return n;
    else
      return 0;
  }
  else{
    int i,j=arr[0];
    rep(i,n){
      lis[i]=1;
    }
    REP(i,1,n){
      REP(j,0,i){
      if(arr[i]>arr[j] && lis[i]<lis[j]+1){
        lis[i]=lis[j]+1;
        cout<<arr[i]<<" ";     
        
      }
      

    }
    }
    int max=INT_MIN;
    rep(i,n){
      if(lis[i]>max)
        max=lis[i];
    }
    return max;
  }
  
}



int main(int argc, char const *argv[])
{
	 int arr[6]={50,3,10,7,40,80};
   cout<<lisDp(arr,6);

	return 0;
}