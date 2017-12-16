/*  Design a method to find the frequency of occurences of any given word in a book. What if this algorithm is ran various times  */

#include<bits/stdc++.h>
using namespace std;
#define R 3
#define C 3
#define f first
#define s second
#define pb push_back
#define pp pop_back
#define mp make_pair
#define ll long long
#define lli long long int
#define ld double
#define ull unsigned long long
#define PI pair < int, int >
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,b) for(i=0;i<b;i++)
#define rep1(i,b) for(i=1;i<=b;i++)
#define pd(n) printf("%d\n",n)
#define pl(n) printf("%lld\n",n)
#define sl(n) scanf("%lld",&n)
#define sd(n) scanf("%d",&n)
#define pn printf("\n")
const int N = 2050;
const int M = 123;
const ld Pi = acos(-1);
const ll Inf = 1e18;
const int inf = 1e9;
const int mod = 1e9 + 7;
const int Sz = 501;
const int MOD = 1e9 + 7;
void add(int &a, int b) {
  a += b;
  if (a >= mod) a -= mod;
}
int mult(int a, int b) {
  return 1ll * a * b % mod;
}

int min(int a,int b,int c){
  if(a<b && a<c)
    return a;
  else if(b<a && b<c)
    return b;
  else
    return c;
}

map<string,int>hashMap;
void hash(string sentence){
  int n=sentence.length();
  string word1;
  int a=1;
  for(int i=0;i<=n;i++){
    if(sentence[i]!=' '&& i!=n && sentence[i]!='.'){
      word1=word1+sentence[i];

    }
    else{
       cout<<i<<" "<<word1<<endl;
      if(hashMap.find(word1)==hashMap.end()){
          hashMap.insert(make_pair(word1,a));
          //cout<<word1<<endl;
        }
      else{
          hashMap[word1]+=1;
          //cout<<"in loo[p"<<word1<<endl;
      }
      word1="";
    }
  }

  // map<string,int>::iterator it;
  // for (it = hashMap.begin(); it!=hashMap.end(); ++it)
  // {
  //   cout<<it[0]<<it[1]<<endl;
  // }
}


int count(string word){
  return hashMap[word];
}



int main(int argc, char const *argv[])
{
	 string sentence,word;
   getline(cin,sentence);
   hash(sentence);
   int n;
   cout<<"Enter number of queries:";
   cin>>n;
   while(n--){
    cout<<"Enter the word you want to query for:"<<endl;
   cin>>word;
   cout<<"Count for this word is"<<count(word);
   }
   

	return 0;
}