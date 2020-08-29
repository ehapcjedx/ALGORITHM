//luogu p1873

#include <cstdio>
#include <algorithm>
using namespace std;

long long a[1000010], n, m;

long long sum(int height)
{
    long long total=0;
    for(int i=0; i<n; i++)
        if(a[i] > height)
            total += a[i]-height;
    return total;
}

int main()
{
    long long maxh=0, lesh, mid;
    scanf("%d%d",&n, &m);
    for(int i=0; i<n; i++)
    {
        scanf("%d", &a[i]);
        maxh = max(maxh,a[i]);
    }
    
    while(lesh <= maxh)
    {
        mid = (maxh+lesh)/2;
        if(sum(mid) >= m)
            lesh = mid+1;
        else
            maxh = mid-1;
    }
    
    printf("%d", lesh-1);

    return 0;
}