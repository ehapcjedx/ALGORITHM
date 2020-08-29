//luogu p4779

#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

struct node{
    int x, dis;
    bool operator <(const node &a)const
    //const表明该函数不会修改数据
    {
        return a.dis<dis;//反向定义小于
    }
};

int m,n,s;
vector< vector<node> > G;
vector<int> sd;
vector<bool> vis;

void dijkstra()
{
    priority_queue<node> q;//最大值排在队首
    node fro;
    int d, np, currentPos;
    sd[s] = 0;
    q.push((node){s,0});
    while (q.size())
    {
        fro = q.top();
        q.pop();
        currentPos = fro.x;
        if(vis[currentPos])
            continue;
        vis[currentPos] = 1;
        for(int i=0; i<G[currentPos].size(); i++)
        {
            d = G[currentPos][i].dis;
            np = G[currentPos][i].x;
            if(vis[np])
                continue;
            if(sd[np] > sd[currentPos]+d)
                sd[np] = sd[currentPos]+d;
            q.push((node){np,sd[np]});
        }
    }
}

int main(){
    int u,v,d;
    node t;
    scanf("%d%d%d",&n,&m,&s);
    G.resize(n+10);
    sd.resize(n+10);
    vis.resize(n+10);
    for(int i=0; i<m; i++)
    {
        scanf("%d%d%d",&u,&v,&d);
        t.x = v;
        t.dis = d;
        G[u].push_back(t);
    }
    for(int i=1; i<=n; i++)
        sd[i] = 0x7fffffff;
    dijkstra();
    for(int i=1; i<=n; i++)
        printf("%d ",sd[i]);
    return 0;
}