
/*  Find if there is a pair with product equal to x  */

#include<bits/stdc++.h>
#include <unordered_set>
using namespace std;

bool isPro(int arr[],int n,int x){
	if(n<2){
		return false;
	}
	unordered_set<int> s;

	for (int i = 0; i < n; ++i)
	{
		if(arr[i]==0){
			if(x==0)
				return true;
			else
				return false;;
		}
		else{
			if(x%arr[i]==0){
				if(s.find(x%arr[i])!=s.end())
					return true;
			}
			s.insert(arr[i]);
		}
		
	}
	return false;
}

int main(int argc, char const *argv[])
{

	int n;
	cin>>n;
	int arr[n];
	for (int i = 0; i < n; ++i)
	{
		/* code */
		cin>>arr[n];
	}
	int x;
	cin>>x;
	isPro(arr,n,x)? cout<<"Yes":cout<<"NO";

	return 0;
}