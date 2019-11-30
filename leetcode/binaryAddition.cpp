#include<iostream>
using namespace std;

string binary_addition(string s1, string s2){
    string result = "";     // Initialize sum
    int s = 0;  // Digit Sum
    int i=s1.size()-1,j = s2.size()-1;
    while(i>=0 || j>=0 || s==1){
        s += i>=0 ? s1[i] - '0' : 0;
        s += j>=0 ? s2[j] - '0' : 0;
        i--;j--;
        result = char(s % 2 + '0') + result;
        s = s/2;
    }
    return result;
}

int main(){
    string s1 = "11";
    string s2 = "1";
    cout<<"Sum of s1 and s2 = : " + binary_addition(s1,s2);
    return 0;
}