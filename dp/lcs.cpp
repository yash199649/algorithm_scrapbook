/* Function to find minimum length common subsequence in two given strings. */
#include<bits/stdc++.h>
using namespace std;

int lcsFunc(char* str1,char* str2,int m,int n){
	
	int lcs[m+1][n+1];

	for (int i = 0; i <=m; i++)
	{
		for (int j = 0; j<=n; j++)
		{	if(i==0||j==0)
				lcs[i][j]=0;
			else if(str1[i]==str2[j])
				lcs[i][j]=lcs[i-1][j-1]+1;
			else
				lcs[i][j]=max(lcs[i-1][j],lcs[i][j-1]);
		}
	}
	return lcs[m][n];

}

int main(int argc, char const *argv[])
{
	char x[] = "yash";
	char y[] = 	"ashwani";
	cout<<"Longest common subsequence length is:"<<lcsFunc(x,y,4,7);
	return 0;
}

