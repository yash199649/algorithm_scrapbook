#include<bits/stdc++.h>
using namespace std;

// Brute Force (Time: O(n^2) | SPace : O(1))
vector<int> twoSum(vector<int>& nums, int target){
    int remainder=0;
    vector<int> result;
    for(int i=0; i<nums.size(); i++) {
        remainder = target - nums[i];
        for(int j=i+1;j<nums.size();j++){
            if(remainder == nums[j]){
                result.push_back(i);
                result.push_back(j);
                break;
            }
        }
        if(result.size()>0){
            break;
        }
    }
    return result;
}

// Using hashMap (Time : O(n) | Space : O(n) n-> size of array)
vector<int> twoSumOptimized(vector<int>& nums, int target){
    vector<int> result;
    map<int,int> remainder;
    for(int i=0;i<nums.size();i++){
        if(remainder.find(nums[i]) != remainder.end()){
            result.push_back(remainder.find(nums[i])->second);
            result.push_back(i);
            return result;
        }
        remainder.insert(pair<int,int>(target-nums[i],i));
    }
    return result;
}

// TODO : Sorting solution (O(logn)) - heapsort/mergesort O(n^2) - quicksort
vector<int> twoSumSortingSolution(vector<int>& nums, int target){
    vector<int> result;
    
}



void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

int stringToInteger(string input) {
        return stoi(input);
}

string integerVectorToString(vector<int> list, int length = -1) {
    if (length == -1) {
        length = list.size();
    }
    if (length == 0) {
        return "[]";
    }
    string result;
    for(int index = 0; index < length; index++) {
        int number = list[index];
        result += to_string(number) + ", ";
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}


int main(){
    String line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);
        getline(cin, line);
        int target = stringToInteger(line);
        vector<int> ret = Solution().twoSum(nums, target);
        string out = integerVectorToString(ret);
        cout << out << endl;
        return 0;
    }
}
