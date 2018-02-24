
/*  Given two rectangles , find if they overlap  */

#include<bits/stdc++.h>
using namespace std;

struct Point
{
	int x,y;
};

int main(int argc, char const *argv[])
{
	Point l1 = {0,10},r1={10,0};  //top left and bottom right coordinates are used to represent a rectangle
	Point l2 = {5,5}, r2={15,0};
	if(l1.x>r2.x || l2.x>r1.x)
		cout<<"Do not Overlap";
	else if(l1.y<r2.y || l2.y<r1.y)
		cout<<"Do not Overlap";
	else
		cout<<"Do overlap";
	return 0;
}