#include<bits/stdc++.h>
using namespace std;

int findMin(vector<int> v,int c){
	static int result=INT_MAX;
	if(c==0)
		return 1;
	for(int i=0;i<v.size();i++){
		if((1+min(findMin(c-v[i])))<result)
			result=(1+min(findMin(c-v[i])));
	}
	return result;
}
int main(int argc, char const *argv[])
{
	vector<int> v;
	int test,c;
	cin>>test;
	while(test--){
		cin>>c;
		for(int i=1;i<=c;i*=2){
			v.push_back(i);
		}
		cout<<findMin(v,c);
	}
	return 0;
}