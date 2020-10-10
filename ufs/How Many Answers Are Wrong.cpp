// HDU-3038
// 带权并查集模板题
// 注意有多组数据

#include <iostream>
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define N 200010
using namespace std;

int pre[N], v[N];

int find(int x)
{
    if(x == pre[x])
        return x;
    int tmp = pre[x];
    pre[x] = find(pre[x]);
    v[x] += v[tmp];
    return pre[x];
}

bool merge(int a, int b, int val)
{
    int fa = find(a);
    int fb = find(b);
    if(fa!=fb)
    {
        pre[fb] = fa;
        v[fb] = v[a]-v[b]+val;
    }
    else
    {
        if(v[fb] != v[a]-v[b]+val)
            return 0;
    }
    return 1;
}

int main()
{
    int n, m, cnt, a, b, val;
    while(cin>>n>>m)
    {
        cnt = 0;
        memset(v, 0, sizeof(int)*N);
        for(int i=0; i<=n; i++)
            pre[i] = i;
        for(int i=0; i<m; i++)
        {
            cin>>a>>b>>val;
            if(!merge(a-1, b, val))
                cnt++;
        } 
        cout<<cnt<<endl;
    }

    return 0;
}
