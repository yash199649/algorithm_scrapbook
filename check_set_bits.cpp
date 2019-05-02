#include<iostream>
#include<cstring>
using namespace std;

string areBitsSetOne(int n){
    if(n==0)
        return "Nope";
    if(((n+1)&n)==0)
        return "Yes";
    return "Nope";
}

int main(int argc, char const *argv[])
{
    int n=7;
    cout<<areBitsSetOne(n);
    return 0;
}