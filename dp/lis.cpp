#include<iostream>
#include<vector>
using namespace std;

int lis(vector<int> v){
	int n = v.size();
	vector<int> dp(n+1,1);
	for(int i=1;i<n;i++){
		for(int j=0;j<i;j++){
			if(v[i]>v[j] && dp[j]+1>dp[i]){
			dp[i] = dp[j]+1;
		}
		}
	}
		
		
	
	int m = 0;
	for(int i=0;i<n;i++){
		if(m<dp[i])
			m=dp[i];
	}
	
	return m;

}

int main(){
	vector<int> v(8);
	for(int i=0;i<8;i++)
		cin>>v[i];
	cout<<lis(v)<<endl;


	return 0;
}