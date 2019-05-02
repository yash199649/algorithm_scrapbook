#include<bits/stdc++.h>
using namespace std;

// Brute Force method

int gasBrute(vector<int>gas,vector<int> cost){
    int n = gas.size();
    if(n<2)
        return 0;
    int totalGas = 0;
    bool isEmpty;

    for(int i=0;i<n;i++){
        totalGas = gas[i];
        isEmpty = false;
        for(int j=1;j<n+1;j++){
            totalGas -= (cost[i+j])%n;
            if(totalGas<0){
                isEmpty=true;
                break;
            }
            totalGas += (gas[i+j])%n;
        }
        if(!isEmpty)
            return i;
    }
    return -1;

}


// Dynamic Programming method

int gasDp(vector<int> gas,vector<int> cost){
    int n = gas.size();
    if(n<2)
        return -1;
    
    int pre = n-1;
    int end = 0;
    int totalCost = gas[end]-cost[end];
    while(pre!=end){
        if(totalCost<0){
            totalCost += gas[pre]-cost[pre];
            pre = (pre+n-1)%n;
        }
        else{
            end = (end+1)%n;
            totalCost += gas[end]-cost[end];
        }
    }
    return pre;
}


int main(){
    vector<int>gas,cost;
    gas.push_back(15);
    gas.push_back(8);
    gas.push_back(2);
    gas.push_back(6);
    gas.push_back(18);
    gas.push_back(9);
    gas.push_back(21);
    gas.push_back(30);
    cost.push_back(8);
    cost.push_back(6);
    cost.push_back(30);
    cost.push_back(9);
    cost.push_back(15);
    cost.push_back(21);
    cost.push_back(2);
    cost.push_back(18);
    cout<<"We can start the tour from : "<<gasDp(gas,cost)<<endl;
    return 0;
    
    
}