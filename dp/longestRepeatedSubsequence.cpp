/*  Print the longest repeating subsequence such 
that the two subsequence dont have same string character at same position. */

#include<bits/stdc++.h>
using namespace std;

string longestRepeatedSubsequence(string str){
	int n= str.length();
	int dp[n+1][n+1];
	for (int i = 0; i <=n; ++i)
	{
		for(int j=0;j <=n;j++){
			dp[i][j]=0;
		}
	}

	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(str[i-1]==str[j-1] && i!=j)
				dp[i][j]=dp[i-1][j-1]+1;
			else
				dp[i][j]= max(dp[i-1][j],dp[i][j-1]);
		}
	}

	string res="";

	int i=n,j=n;
	while(i>0 && j>0){
		if(dp[i][j]==dp[i-1][j-1]+1){
			res = res+str[i-1];
			i--;
			j--;
		}
		else if(dp[i][j]==dp[i-1][j]){
			i--;
		}
		else
			j--;
	}
	reverse(res.begin(),res.end());
	return res;
}

int main(int argc, char const *argv[])
{
	string str = "aabb";
	cout<<longestRepeatedSubsequence(str);
	return 0;
}