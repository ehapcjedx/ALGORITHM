// POJ-1847
// dijkstra
// 注意通向非默认路口的权值都是1

#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

struct node{
    int x, dis;
    node(int a=0, int b=0):x(a), dis(b) {}
    bool operator<(const node& a)const{
        return a.dis<dis;
    }
};

int v, e;
vector< vector<node> > G;
int sd[103];
bool vis[103];

void dijkstra(int n)
{
    memset(sd, 0x3f, sizeof(int)*103);
    priority_queue<node> q;
    node fro, next;
    sd[n] = 0;
    q.push(node(n, 0));
    while(!q.empty())
    {
        fro = q.top();
        q.pop();
        if(!vis[fro.x])
        {
            vis[fro.x] = 1;
            for(int i=0; i<G[fro.x].size(); i++)
            {
                next = G[fro.x][i];
                if(vis[next.x]==1)
                    continue;
                sd[next.x] = min(sd[fro.x]+next.dis, sd[next.x]);
                next.dis = sd[next.x];
                q.push(next);
            }
        }
    }
}

int main()
{
    int a, b, n, next;
    scanf("%d%d%d", &v, &a, &b);
    G.resize(v+5);
    for(int i=1; i<=v; i++)
    {
        scanf("%d", &n);
        for(int j=0; j<n; j++)
        {
            scanf("%d", &next);
            G[i].push_back(node(next, min(j, 1)));
        }
    }
    dijkstra(a);
    if(vis[b]==1)
        printf("%d\n", sd[b]);
    else
        printf("-1\n");

    return 0;
}