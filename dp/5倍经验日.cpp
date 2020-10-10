//luogu p1802
//5倍经验日

#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
    int n, x;
    int lose, win, use;

    scanf("%d%d", &n, &x);
    long long dp[x+5] = {0};

    for(int i=0; i<n; i++)
    {
        scanf("%d%d%d", &lose, &win, &use);
        for(int j=0; j<=x; j++)
            dp[j] += lose;
        for(int j=x; j-use>=0; j--)
            dp[j] = max(dp[j-use]+win-lose, dp[j]);
    }

    printf("%ld", dp[x]*5);

    return 0;
}