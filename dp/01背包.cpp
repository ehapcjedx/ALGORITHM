//luogu p1048
//01背包

#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int t, m;
    int time, value;
    int dp[1005] = {0};

    cin>>t>>m;

    for(int i=0; i<m; i++)
    {
        cin>>time>>value;
        for(int j=t; j-time>=0; j--)
            dp[j] = max(dp[j-time]+value, dp[j]);
    }

    cout<<dp[t];

    return 0;
}
