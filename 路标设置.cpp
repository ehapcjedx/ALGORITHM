//luogu p3853

#include <cstdio>
using namespace std;

int a[100010], l, n, k;

bool check(int index)
{
    int len, num=0;
    for(int i=0; i<n-1; i++)
    {
        len = a[i+1]-a[i];
        num += len/index;
        if(len%index == 0)
            num--;
    }
    if(num>k)
        return 0;
    else
        return 1;
}

int main()
{
    int left=0, right, mid;
    scanf("%d%d%d", &l, &n, &k);
    for(int i=0; i<n; i++)
        scanf("%d", &a[i]); 
    right = a[n-1];

    while(left <= right)
    {
        mid = (left+right)/2;
        if(check(mid) == 1)
            right = mid-1;
        else
            left = mid+1;
    }

    printf("%d", right+1);
    return 0;
}