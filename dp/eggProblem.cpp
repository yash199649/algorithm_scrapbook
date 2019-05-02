#include<bits/stdc++.h>
using namespace std;

int ways(int n, int k)
{
    if (k == 1 || k == 0)
        return k;
    if (n == 1)
        return k;
    int min = 99999, x, res;
    for (x = 1; x <= k; x++)
    {
        res = max(ways(n-1, x-1), ways(n, k-x));
        if (res < min)
            min = res;
    }
 
    return min + 1;
}

int dpWays(int n, int k)
{
    int dp[n+1][k+1];
    int res;
    int i, j, x;
    for (i = 1; i <= n; i++)
    {
        dp[i][1] = 1;
        dp[i][0] = 0;
    }
    for (j = 1; j <= k; j++)
        dp[1][j] = j;
    for (i = 2; i <= n; i++)
    {
        for (j = 2; j <= k; j++)
        {
            dp[i][j] = 999999;
            for (x = 1; x <= j; x++)
            {
                res = 1 + max(dp[i-1][x-1], dp[i][j-x]);
                if (res < dp[i][j])
                    dp[i][j] = res;
            }
        }
    }
    return dp[n][k];
}

int main(){
    int n=2,k=36;
    cout<<"No. of possible ways: "<<dpWays(n,k)<<endl;
    return 0;
}