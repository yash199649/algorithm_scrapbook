/* Function to find minimum length common subsequence in two given strings. */
#include<iostream>
using namespace std;

//Recursive Solution
int lcsRecur(char* str1, char* str2, int m,int n){
	if(m==0||n==0)
		return 0;
	if(str1[m]==str2[n])
		return lcsRecur(str1,str2,m-1,n-1)+1;
	else
		return max(lcsRecur(str1,str2,m-1,n),lcsRecur(str1,str2,m,n-1));
}

// Dp solution
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
	cout<<"Longest common subsequence length is:"<<lcsRecur(x,y,4,7)<<endl;
	return 0;
}

