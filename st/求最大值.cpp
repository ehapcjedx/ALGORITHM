// NC14402
// 由图像可知最大值在相邻点中产生
// 有多组数据！！！！

#include <iostream>
#include <cstdio>
#include <algorithm>
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
const int N = 2e5+10;

int a[N], t[4*N], n, m;

inline int ls(int p) {return p<<1;}
inline int rs(int p) {return p<<1|1;}

inline void push_up(int p)
{
    t[p] = max(t[ls(p)], t[rs(p)]);
}

void build(int p, int l, int r)
{
    if(l==r) {
        t[p] = a[l+1]-a[l];
        return;
    }
    int mid = (l+r)>>1;
    build(ls(p), l, mid);
    build(rs(p), mid+1, r);
    push_up(p);
}

void update(int p, int x, int l, int r, int val)
{
    if(l==r) {
        t[p] = a[l+1]-a[l];
        return;
    }
    int mid = (l+r)>>1;
    if(x<=mid)
        update(ls(p), x, l , mid, val);
    else
        update(rs(p), x, mid+1, r, val);
    push_up(p);
}

int main()
{
    IOS
    int c, d;
    while(cin>>n) {
        for(int i=1; i<=n; i++)
            cin>>a[i];
        build(1, 1, n-1);
        cin>>m;
        for(int i=0; i<m; i++)
        {
            cin>>c>>d;
            a[c] = d;
            if(c!=1)
                update(1, c-1, 1, n-1, a[c]-a[c-1]);
            if(c!=n)
                update(1, c, 1, n-1, a[c+1]-a[c]);
            printf("%d.00\n", t[1]);
        }
    }
    return 0;
}
