// luogu p1020
// LIS问题

#include <iostream>
#include <cstdio>
#include <algorithm>
#define N 100005
using namespace std;

int a[N], dp[N];

int main()
{
    int n = 0, len = 1;
    while (scanf("%d", &a[++n]) != EOF); 
    n--;

    // cin>>n;
    // for(int i=0; i<n; i++)
    //     cin>>a[i+1];

    dp[1] = a[1];
    for(int i=2; i<=n; i++)
    {
        int l=1, r=len, mid;
        if(a[i] <= dp[len])
            dp[++len] = a[i];
        else
        {
            while(l<r)
            {
                mid = (l+r)/2;
                if(a[i]>dp[mid])
                    r = mid;
                else
                    l = mid+1;
            }
            dp[l] = max(dp[l], a[i]);
        } 
    }

    cout<<len<<endl;

//  对于问二求整个数列的最长上升子序列即可。证明如下：
// （1）假设打导弹的方法是这样的：取任意一个导弹，从这个导弹开始将能打的导弹全部打完。而这些导弹全部记为为同一组，再在没打下来的导弹中任选一个重复上述步骤，直到打完所有导弹。
// （2）假设我们得到了最小划分的K组导弹，从第a(1<=a<=K)组导弹中任取一个导弹，必定可以从a+1组中找到一个导弹的高度比这个导弹高（因为假如找不到，那么它就是比a+1组中任意一个导更高，在打第a组时应该会把a+1组所有导弹一起打下而不是另归为第a+1组），同样从a+1组到a+2组也是如此。那么就可以从前往后在每一组导弹中找一个更高的连起来，连成一条上升子序列，其长度即为K;
// （3）设最长上升子序列长度为P，则有P>=K;又因为最长上升子序列中任意两个不在同一组内(否则不满足单调不升)，则有P<=K，所以K=P。

    len = 1;
    dp[1] = a[1];
    for(int i=2; i<=n; i++)
    {
        int l=1, r=len, mid;
        if(a[i] > dp[len])
            dp[++len] = a[i];
        else
        {
            while(l<r)
            {
                mid = (l+r)/2;
                if(a[i]<=dp[mid])
                    r = mid;
                else
                    l = mid+1;
            }
            dp[l] = min(dp[l], a[i]);
        } 
    }

    cout<<len;

    return 0;
}