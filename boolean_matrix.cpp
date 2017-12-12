#include <iostream>
using namespace std;


#define R 4
#define C 4

void makeRow(bool arr[R][C],int R){
	for(int i=0;i<C;i++)
		arr[R][i]=1;
}
void makeCol(bool arr[R][C],int C){
	for(int i=0;i<R;i++)
		arr[i][C]=1;
}

void modifyMatrix(bool arr[R][C]){
	for (int i = 0; i < R; ++i)
	{
		for (int i = 0; i < C; ++i)
		{
			if(arr[i][j]==1)
			{
				makeCol(arr,j);
				makeRow(arr,i);
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	int arr[R][C];
	for (int i = 0; i < R; ++i)
	{
		for (int i = 0; i < C; ++i)
		{
			cin>>arr[i][j];
		}
	}

	modifyMatrix(arr);
	for (int i = 0; i < R; ++i)
	{
		for (int i = 0; i < C; ++i)
		{
			cout<<arr[i][j];
		}
		cout<<endl;
	}

	return 0;
}