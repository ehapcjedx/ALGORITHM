// luogu p1091
// 枚举每个元素对左右分别求LIS，O(n^2logn)

#include <iostream>
#include <cstring>
using namespace std;
const int N = 110;

int a[N], dp[N], n;

int LIS(int fr, int to)
{
    int len = 1;
    memset(dp, 0x3f, sizeof(dp));
    dp[1] = a[fr];
    for(int i=fr+1; i<=to; i++)
    {
        int l=1, r=len, mid;
        if(a[i] > dp[len])
            dp[++len] = a[i];
        else
        {
            while(l < r){
                mid = (l+r)>>1;
                if(a[i] <= dp[mid])
                // 注意此处应是小于等于，等价于upper_bound，否则可能导致不严格单调
                    r = mid;
                else
                    l = mid+1;
            }
            dp[l] = min(a[i], dp[l]);
        }
    }
    return len;
}

int LDS(int fr, int to)
{
    int len = 1;
    memset(dp, 0, sizeof(dp));
    dp[1] = a[fr];
    for(int i=fr+1; i<=to; i++)
    {
        int l=1, r=len, mid;
        if(a[i] < dp[len])
            dp[++len] = a[i];
        else
        {
            while(l < r){
                mid = (l+r)>>1;
                if(a[i] >= dp[mid])
                    r = mid;
                else
                    l = mid+1;
            }
            dp[l] = max(a[i], dp[l]);
        }
    }
    return len;
}

int main()
{
    cin>>n;
    int ans = n, len1, len2;
    for(int i=1; i<=n; i++)
        cin>>a[i];

    for(int i=1; i<=n; i++)
    {
        len1 = LIS(1, i);
        len2 = LDS(i, n);
        ans = min(ans, n-len1-len2+1);
    }
    cout<<ans<<endl;

    return 0;
}
