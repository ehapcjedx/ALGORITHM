// luogu p3373

#include <iostream>
#define ll long long
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
const int N = 1e5+10;

int m, n;
ll a[N], t[4*N], tag[4*N];

inline int ls(int p) {return p<<1;}
inline int rs(int p) {return p<<1|1;}

inline void push_up(int p)
{
    t[p] = t[ls(p)]+t[rs(p)];
}

inline void f(int p, int l, int r, int k)
{
   tag[p] += k;
   t[p] += k*(r-l+1);
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
        t[p] = a[l];
        return;
    }
    int mid = (l+r)>>1;
    build(ls(p), l, mid);
    build(rs(p), mid+1, r);
    push_up(p);
}

inline void add(int p, int nl, int nr, int l, int r , int k)
{
    if(nl<=l && r<=nr) {
        tag[p] += k;
        t[p] += (r-l+1)*k;
        return;
    }
    push_down(p, l, r);
    int mid = (l+r)>>1;
    if(nl<=mid)
        add(ls(p), nl, nr, l, mid, k);
    if(nr>=mid+1)
        add(rs(p), nl, nr, mid+1, r, k);
    push_up(p);
}

ll query(int p, int ql, int qr, int l, int r)
{
    if(ql<=l && r<=qr)
        return t[p];
    int mid = (l+r)>>1;
    ll res = 0;
    push_down(p, l, r);
    if(ql<=mid)
        res+=query(ls(p), ql, qr, l, mid);
    if(qr>=mid+1)
        res+=query(rs(p), ql, qr, mid+1, r);
    return res;
}

int main()
{
    int opt, x, y, k;
    cin>>n>>m;
    for(int i=1; i<=n; i++)
        cin>>a[i];
    build(1, 1, n);
    for(int i=0; i<m; i++)
    {
        cin>>opt>>x>>y;
        if(opt==1) {
            cin>>k;
            add(1, x, y, 1, n, k);
        }
        else
            cout<<query(1, x, y, 1, n)<<endl;
    }
    return 0;
}
