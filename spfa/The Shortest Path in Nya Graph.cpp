// HDU-4725
// 链式前向星+dijkstra，关键在建图
// 这里可以为每个层建立一个点，姑且就叫每个层的层点，该层点有通向相邻层所有点的双向边，权值为c，并且该层点还有通向本层所有点的单向边。因此总共需要2N个点，1-N为编号的点，N+1-2N为层点。
// 一定要看清边的方向

#include <cstdio>
#include <queue>
using namespace std;
const int N = 3e5+5;
const int M = 9e5+5;

struct edge{
    int next, to, w;
};
struct node{
    int x, dis;
    node(int a=0, int b=0):x(a), dis(b) {}
    bool operator<(const node& a)const{
        return dis>a.dis;
    }
};

edge e[M];
bool vis[N];
int head[N], sd[N], cnt = 0;
void adde(int f, int t, int w) {
    e[++cnt].next = head[f];
    e[cnt].w = w;
    e[cnt].to = t;
    head[f] = cnt;
}

int t, n, m, c, tmp, f, to;

void init()
{
    cnt = 0;
    memset(vis, 0, N);
    memset(sd, 0x3f, sizeof(int)*N);
    memset(e, 0, sizeof(edge)*M);
    memset(head, 0, sizeof(int)*N);
}

void dijkstra()
{
    priority_queue<node> q;
    node fro, beg(1, 0);
    int next, nexto, nextw;
    q.push(beg);
    sd[1] = 0;

    while(!q.empty())
    {
        fro = q.top();
        q.pop();
        if(!vis[fro.x])
        {
            vis[fro.x] = 1;
            next = head[fro.x];
            while(next != 0)
            {
                nexto = e[next].to;
                nextw = e[next].w;
                if(!vis[nexto])
                {
                    if(sd[nexto]>sd[fro.x]+nextw)
                    {
                        sd[nexto] = sd[fro.x]+nextw;
                        q.push(node(nexto, sd[nexto]));
                    }
                }
                next = e[next].next;
            }
        }
    }
}

int main()
{
    scanf("%d", &t);
    for(int i=0; i<t; i++)
    {
        scanf("%d%d%d", &n, &m, &c);
        init();
        for(int j=1; j<=n; j++)
        {
            scanf("%d", &tmp);
            adde(tmp+n, j, 0); //建立该点与本层结点的边,权值为0,单向边
			if (tmp-1 >= 1)
                adde(j, tmp+n-1, c), adde(tmp+n-1, j, c); //建立每个点与上、下层结点的边，权值为c
			if (tmp+1 <= n)
                adde(j, tmp+n+1, c), adde(tmp+n+1, j, c);
        }

        for(int j=0; j<m; j++)
        {
            scanf("%d%d%d", &f, &to, &tmp);
            adde(f, to, tmp);
            adde(to, f, tmp); // 是双向边！！！！！
        }
        dijkstra();
        if(!vis[n])
            sd[n] = -1;
        printf("Case #%d: %d\n", i+1, sd[n]);
    }
    return 0;
}
