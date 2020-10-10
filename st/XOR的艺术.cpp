// luogu p2574

#include <iostream>
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
const int N = 2e5+10;

char a[N];
int n, m;
int t[4*N], tag[4*N];

inline int ls(int p) {return p<<1;}
inline int rs(int p) {return p<<1|1;}

inline void push_up(int p)
{
    t[p] = t[ls(p)]+t[rs(p)];
}

inline void f(int p, int l, int r, int k)
{
    tag[p]^=k;
    t[p] = r-l+1-t[p];
}

inline void push_down(int p, int l, int r)
{
    int mid = (l+r)>>1;
    if(tag[p]) {
        f(ls(p), l, mid, tag[p]);
        f(rs(p), mid+1, r, tag[p]);
        tag[p] = 0;
    }
}

void build(int p, int l, int r)
{
    if(l==r) {
        t[p] = a[l]-48;
        return;
    }
    int mid = (l+r)>>1;
    build(ls(p), l, mid);
    build(rs(p), mid+1, r);
    push_up(p);
}

void change(int p, int nl, int nr, int l, int r)
{
    if(nl<=l && r<=nr) {
        f(p, l, r, 1);
        return;
    }
    int mid = (l+r)>>1;
    push_down(p, l, r);
    if(nl<=mid)
        change(ls(p), nl, nr, l, mid);
    if(nr>=mid+1)
        change(rs(p), nl, nr, mid+1, r);
    push_up(p);
}

int query(int p, int ql, int qr, int l, int r)
{
    if(ql<=l && r<=qr) {
        return t[p];
    }
    int res = 0;
    int mid = (l+r)>>1;
    push_down(p, l, r);
    if(ql<=mid)
        res+=query(ls(p), ql, qr, l, mid);
    if(qr>=mid+1)
        res+=query(rs(p), ql, qr, mid+1, r);
    return res;
}

int main()
{
    IOS
    int opt, x, y;
    cin>>n>>m;
    for(int i=1; i<=n; i++)
        cin>>a[i];
    build(1, 1, n);
    for(int i=0; i<m; i++)
    {
        cin>>opt>>x>>y;
        if(opt==0) {
            change(1, x, y, 1, n);
        }
        else if(opt==1) {
            cout<<query(1, x, y, 1, n)<<endl;
        }
    }
    return 0;
}
