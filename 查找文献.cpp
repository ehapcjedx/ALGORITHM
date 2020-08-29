//luogu p5318

#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int M,N;
vector< vector<int> > G;
vector<bool> visd,visb;

void dfs(int x)//深搜用递归
{
    int next;
    visd[x] = 1;
    printf("%d ",x);
    for(int i=0; i<G[x].size(); i++)
    {
        next = G[x][i];
        if(visd[next] == 0)
            dfs(next);
    }
}

void bfs(int x)//广搜用队列
{
    queue<int> q;
    int next,fro;
    q.push(x);
    printf("%d ",x);
    visb[x] = 1;
    while(q.size())
    {
        fro = q.front();
        for(int i=0; i<G[fro].size(); i++)
        {
            next = G[fro][i];
            if(visb[next] == 0)
            {
                printf("%d ",next);
                visb[next] = 1;
                q.push(next);
            }
        }
        q.pop();
    }
}

int main(){
    int u,v;
    scanf("%d%d", &N, &M);
    G.resize(N+10);
    visd.resize(N+10);
    visb.resize(N+10);
    for(int i=0; i<M; i++)
    {
        scanf("%d%d", &u, &v);
        G[u].push_back(v);
    }
    for(int i=0; i<G.size(); i++)
        sort(G[i].begin(),G[i].end());
    dfs(1);
    printf("\n");
    bfs(1);
    return 0;
}