
/*  Given an array, find the nearest smaller number for every element such that the smaller number is on the left side.s  */


#include<iostream>
#include <stack>
using namespace std;

int main(int argc, char const *argv[])
{
	stack<int> s;
	int n;
	cin>>n;
	int arr[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>arr[i];
	}

	for (int i = 0; i < n; ++i)
	{
		while(!s.empty() && s.top()>=arr[i])
			s.pop();
		if(s.empty())
			cout<<"_ ";
		else
			cout<<s.top();
		s.push(arr[i]);
	}


	return 0;
}