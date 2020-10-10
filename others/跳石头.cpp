//luogu p2678

#include <cstdio>
using namespace std;

int a[50010], l, n, m;

bool check(int minlen)
{
    int len, num=0, i=0, k, j=0;

    if(a[i] != 0)
    {
        k = 0;
        len = a[i];
        while(len < minlen)
        {
            k++;
            if(i+k >= n) {j=1; break;}
            len = a[i+k];
            num++;
        }
        i+=k;
    }
    for(k=1; i<n-1; i+=k)
    {
        k = 1;
        len = a[i+k]-a[i];
        while(len < minlen)
        {
            k++;
            if(i+k >= n) {j=1; break;}
            len = a[i+k]-a[i];
            num++;
        }
    }

    if(j==1) { i-=k; num++; }
    len = l-a[i];
    if(len < minlen)
        num++;

    if(num > m)
        return 0;
    else
        return 1;
}

int main()
{
    int left=0, right, mid;
    scanf("%d%d%d", &l, &n, &m);
    for(int i=0; i<n; i++)
        scanf("%d", &a[i]);
    right = l;

    while(left <= right)
    {
        mid = (left+right)/2;
        if(check(mid) == 1)
            left = mid+1;
        else
            right = mid-1;
    }

    printf("%d",left-1);
    return 0;
}
