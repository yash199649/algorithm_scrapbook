/*  Numbers that have only 2,3 and 5 as their prime factors */

#include<bits/stdc++.h>
using namespace std;
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

// Simple function to divide the given number with the maximum divisiors of 2,3 and 5 and check if the remainder is 1
// Brute Force
int isUgly(int n){
int count =0;
int i=1,j;
while(count<n)
{
	j=i;
	while(j%2==0)
		j=j/2;
	while(j%3==0)
		j=j/3;
	while(j%5==0)
		j=j/5;
	if(j==1)
		count+=1;
	i+=1;
}

return i-1;
}

int min(int a,int b,int c){
	if(a<b && a<c)
		return a;
	else if(b<a && b<c)
		return b;
	else
		return c;
}
//Dp approach

int isUglyDp(int n){
	int ugly[n]; 
    int i2 = 0, i3 = 0, i5 = 0;
    int next_multiple_of_2 = 2;
    int next_multiple_of_3 = 3;
    int next_multiple_of_5 = 5;
    int next_ugly_no = 1;
 
    ugly[0] = 1;
    for (int i=1; i<n; i++)
    {
       next_ugly_no = min(next_multiple_of_2,
                           min(next_multiple_of_3,
                               next_multiple_of_5));
       ugly[i] = next_ugly_no;
       if (next_ugly_no == next_multiple_of_2)
       {
           i2 = i2+1;
           next_multiple_of_2 = ugly[i2]*2;
       }
       if (next_ugly_no == next_multiple_of_3)
       {
           i3 = i3+1;
           next_multiple_of_3 = ugly[i3]*3;
       }
       if (next_ugly_no == next_multiple_of_5)
       {
           i5 = i5+1;
           next_multiple_of_5 = ugly[i5]*5;
       }
    } 
    return next_ugly_no;
}


int main(int argc, char const *argv[])
{
	pd(isUglyDp(150));
	return 0;
}