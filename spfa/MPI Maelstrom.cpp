// POJ-1502
// dijsktra+邻接矩阵存图

#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
#define N 105
using namespace std;

struct node{
    int x, dis;
    node(int a=0, int d=0):x(a), dis(d) {}
    bool operator<(const node& a)const{
        return dis>a.dis;
    }
};
int n, m, vis[N], sd[N];
int G[N][N];

void dijkstra()
{
    for(int i=0; i<=N; i++)
        sd[i] = 0x7fffffff;
    priority_queue<node> q;
    int fro;
    q.push(node(1));
    sd[1] = 0;

    while(!q.empty())
    {
        fro = q.top().x;
        q.pop();
        if(!vis[fro])
        {
            vis[fro] = 1;
            for(int i=1; i<=n; i++)
                if(!vis[i] && G[fro][i]!=-1)
                {
                    if(sd[i]>sd[fro]+G[fro][i])
                    {
                        sd[i] = sd[fro]+G[fro][i];
                        q.push(node(i, sd[i]));
                    }
                }
        }
    }
}

int main()
{
    string str;
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<i; j++)
        {
            cin>>str;
            if(str[0] != 'x')
                G[i][j] = atoi(str.c_str());
                // stoi编译错误
            else
                G[i][j] = -1;
                G[j][i] = G[i][j];
        }
        G[i][i] = 0;
    }

    dijkstra();
    for(int i=1; i<=n; i++)
        m = max(sd[i], m);
    printf("%d\n", m);
    
    return 0;
}
