//luogu p1048
//完全背包

#include <cstdio>
#include <algorithm>
using namespace std;

long long dp[10000005];

int main()
{
    int t, m;
    int time, value;

    scanf("%d%d", &t, &m);

    for(int i=0; i<m; i++)
    {
        scanf("%d%d", &time, &value);
        for(int j=time; j<=t; j++)
            dp[j] = max(dp[j-time]+value, dp[j]);
    }

    printf("%ld", dp[t]);

    return 0;
}