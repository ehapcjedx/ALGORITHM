#include <iostream>
#define ls p<<1
#define rs p<<1|1
using namespace std;
const int N = 100;

int a[N], t[4*N], tag[4*N];

inline void push_up(int p)
{
    t[p] = t[ls]+t[rs];
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
        f(ls, l, mid, tag[p]);
        f(rs, mid+1, r, tag[p]);
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
    build(ls, l, mid);
    build(rs, mid+1, r);
    push_up(p);
}

void update(int p, int nl, int nr, int l, int r, int k)
{
    if(nl<=l && r<=nr) {
        f(p, l, r, k);
        return;
    }
    push_down(p, l, r);
    int mid = (l+r)>>1;
    if(nl<=mid)
        update(ls, nl, nr, l , mid, k);
    if(nr>=mid+1)
        update(rs, nl, nr, mid+1, r, k);
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
        res+=query(ls, ql, qr, l, mid);
    if(qr>=mid+1)
        res+=query(rs, ql, qr, mid+1, r);
    return res;
}

int main()
{
    return 0;
}
