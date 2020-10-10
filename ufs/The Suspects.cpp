// POJ-1611
// 并查集，注意输入格式以及结束条件

#include <cstdio>
#define N 30005
using namespace std;

int pre[N];

void init(int n)
{
    for(int i=0; i<n+3; i++)
        pre[i] = i;
}

int find(int a)
{
    if(pre[a]!=a && pre[a]>=0)
        pre[a] = find(pre[a]);
    return pre[a];
}

void merge(int a, int b)
{
    int fa = find(a);
    int fb = find(b);
    if(fa != fb)
        pre[fa] = fb;
}

int main()
{
    int n, m, k, s, t, f;
    while(scanf("%d%d", &n, &m))
    {
        if (!n && !m)
            break;
        init(n);
        int count = 1;
        for(int i=0; i<m; i++)
        {
            scanf("%d", &k);
            scanf("%d", &s);
            for(int j=1; j<k; j++)
            {
                scanf("%d", &t);
                merge(t, s);
            }
        }

        f = find(0);
        for(int i=1; i<=n-1; i++)
            if(f == find(i))
                count++;
        printf("%d\n", count);
    }

    return 0;
}