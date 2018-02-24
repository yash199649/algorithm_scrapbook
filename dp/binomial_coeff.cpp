/*  Function that takes values of n and k and returns binomial coefficient C(n,k). */

#include<bits/stdc++.h>
using namespace std;

// Recursive approach
int calBinomial(int n,int k){
	if(k==0 || k==n)
		return 1;
	return calBinomial(n-1,k-1)+calBinomial(n-1,k);
}

// Dp approach
int calBinomialDp(int n,int k){
	int C[n+1][k+1];
	for (int i = 0; i <=n; ++i)
	{
		for (int j = 0; j <=min(n,k); ++j)
		{
			if(j==0 || j==i)
				C[i][j]=1;
			else
				C[i][j]=C[i-1][j-1]+C[i-1][j];
		}
	}
	return C[n][k];
}

// Space Effecient approach

int calBinomialSe(int n,int k){
	int C[k+1];
	memset(C,0,sizeof(C));
	C[0]=1;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = min(i,k); j>0; --j)
		{
			C[j]=C[j]+C[j-1]
		}
	}
	return C[k];
}

int main(int argc, char const *argv[])
{
	int n=5,k=2;
	cout<<calBinomial(n,k)<<" "<<calBinomialDp(n,k);
	return 0;
}
