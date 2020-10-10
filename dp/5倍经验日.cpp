// luogu p1802
// 01背包变形

#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 1010;

long long dp[N];

int main()
{
    int n, x;
    int lose, win, use;

    scanf("%d%d", &n, &x);

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
