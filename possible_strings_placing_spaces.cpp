	/* Print all possible strings that can be made by placing spaces
	 in between every postions in a given string */

	#include<bits/stdc++.h>
	using namespace std;

	void printString(char c[],char buffer[],int i,int j,int n){
		if(i==n)
		{
			buffer[j]='\0';
			cout<<buffer<<endl;
			return;
		}

		buffer[j]=c[i];
		printString(c,buffer,i+1,j+1,n);
		buffer[j]=' ';
		buffer[j+1]=c[i];
		printString(c,buffer,i+1,j+2,n);

	}

	int main(int argc, char const *argv[])
	{
		char str[]="ABCD";
		int n=strlen(str);
		char buffer[2*n];
		buffer[0]=str[0];
		printString(str,buffer,1,1,n);
		return 0;
	}		