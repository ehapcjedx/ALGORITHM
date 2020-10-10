// NC15520
// sg打表+dfs搜索

#include <iostream>
#include <set>
#include <vector>
#include <cstring>
#define N 10010
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

int T, n, r, sg[N];
bool vis[N];
vector< vector<int> > G;

int mex(const set<int>& s)
{
    for(int i=0; i<=n; i++)
        if(s.find(i)==s.end())
            return i;
    return -1;
}

void cal_sg(int n)
{
    int next;
    set<int> s;
    vis[n] = 1;
    for(int i=0; i<G[n].size(); i++)
    {
        next = G[n][i];
        if(!vis[next])
        {
            cal_sg(next);
            s.insert(sg[next]);
        }
    }
    sg[n] = mex(s);
}

int main()
{
    IOS
    int a, b;
    cin>>T;

    for(int i=0; i<T; i++)
    {
        memset(sg, 0, sizeof(int)*N);
        memset(vis, 0, N);
        cin>>n>>r;
        G.clear();
        G.resize(n+10);
        for(int j=0; j<n-1; j++)
        {
            cin>>a>>b;
            G[a].push_back(b);
            G[b].push_back(a);
        }
        cal_sg(r);
        if(sg[r] == 0)
            cout<<"Dui"<<endl;
        else
            cout<<"Gen"<<endl;
    }

    return 0;
}
