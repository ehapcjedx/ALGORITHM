// luogu p3368
// 差分+树状数组

#include <iostream>
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long
using namespace std;
const int N = 5e5+10;

inline int lowbit(int x) { return x&(-x);}

ll a[N];
int n, m;

ll query(int x)
{
    ll res = 0;
    while(x) {
        res += a[x];
        x -= lowbit(x);
    }
    return res;
}

void update(int x, ll val)
{
    while(x<=n) {
        a[x] += val;
        x += lowbit(x);
    }
}

int main()
{
    IOS
    ll pre=0, tmp, opt, x, y, k;
    cin>>n>>m;
    for(int i=1; i<=n; i++)
    {
        cin>>tmp;
        update(i, tmp-pre);
        pre = tmp;
    }
    for(int i=0; i<m; i++)
    {
        cin>>opt;
        if(opt==1) {
            cin>>x>>y>>k;
            update(x, k);
            update(y+1, -k);
        }
        if(opt==2) {
            cin>>x;
            cout<<query(x)<<endl;
        }
    }

    return 0;
}
