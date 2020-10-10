// lupgu p3374
// 树状数组板子

#include <iostream>
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
const int N = 5e5+10;

int a[N], n, m, opt, x, y, k;

inline int lowbit(int x) { return x&(-x);}

int query(int x)
{
    int res = 0;
    while(x){
        res += a[x];
        x -= lowbit(x);
    }
    return res;
}

void add(int x, int val)
{
    while(x<=n){
        a[x] += val;
        x += lowbit(x);
    }
}

int main()
{
    IOS
    cin>>n>>m;
    for(int i=1; i<=n; i++)
    {
        cin>>x;
        add(i, x);
    }
    for(int i=0; i<m; i++)
    {
        cin>>opt;
        if(opt==1)
        {
            cin>>x>>k;
            add(x, k);
        }
        else if (opt==2)
        {
            cin>>x>>y;
            cout<<query(y)-query(x-1)<<endl;
        }
    }
    return 0;
}
