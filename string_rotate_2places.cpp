#include <iostream>
using namespace std;


bool isRotated(string s1,string s2){
	if(s1.length()!=s2.length()){
		return false;
	}
	string clock_rotate="";
	string anti_clock_rotate="";
	int len = s1.length();

	clock_rotate = clock_rotate + s1.substr(2) + s1.substr(0,2);
	anti_clock_rotate = anti_clock_rotate + s1.substr(len-2,2)+ s1.substr(0,len-2);

	if(s2.compare(clock_rotate) ==0 || s2.compare(anti_clock_rotate)==0)
		return true;
	return false;
}

int main(int argc, char const *argv[])
{
	 string str1 = "geeks";
    string str2 = "ekseg";
 
    isRotated(str1, str2) ? cout << "Yes"
                          : cout << "No";
	return 0;
}