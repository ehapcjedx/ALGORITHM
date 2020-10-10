// luogu p1439
// 最长公共子序列（LCS）

#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;

// 朴素算法, O(n^2), 会被10^5卡死
// int main()
// {
//     int n;
//     scanf("%d", &n);
//     int dp[n+5] = {0}, a1[n+5], a2[n+5];
//     for(int i=0; i<n; i++)
//         scanf("%d", &a1[i+1]);
//     for(int i=0; i<n; i++)
//         scanf("%d", &a2[i+1]);

//     for(int i=1; i<=n; i++)
//         for(int j=1; j<=n; j++)
//             if(a1[i] == a2[j])
//                 dp[j] = max(dp[j], dp[j-1])+1;
//             else
//                 dp[j] = max(dp[j], dp[j-1]);

//     printf("%d", dp[n]);

//     return 0;
// }

// 利用排列的性质, 转化为LIS, O(nlogn)
int main()
{
    int n, len = 1, a;
	scanf("%d", &n);
    int a1[n+5], a2[n+5], dp[n+5];
	for(int i=1; i<=n; i++)
	{
		scanf("%d", &a);
        a1[a] = i;
		dp[i] = 0x7fffffff;
	}
    for(int i=1; i<=n; i++)
    {
        scanf("%d", &a);
        a2[i] = a1[a];
    }

	dp[1] = a2[1];

	for(int i=2; i<=n; i++)
	{
		int l=1, r=len, mid;
		if(a2[i] > dp[len])
            dp[++len] = a2[i];
		else 
		{
            while(l<r)
            {
                mid = (l+r)/2;
                if(a2[i] <= dp[mid])
                    r = mid;
                else
                    l = mid+1; 
            }
            dp[l] = min(a2[i],dp[l]);
     	}
    }

    printf("%d", len);

    return 0;
}