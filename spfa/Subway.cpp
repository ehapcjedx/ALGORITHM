// POJ-2502
// 为什么G++可以C++就不过啊啊啊啊啊啊啊

#include <iostream>
#include <cmath>
#include <queue>
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define N 300
using namespace std;
const double INF = 1e18;

struct node{
    int x;
    double dis;
    node(int i=0, double d=0):x(i), dis(d) {}
    bool operator<(const node& n)const{
        return dis>n.dis;
    }
};
struct pos{
    double x, y;
};

bool vis[N];
double sd[N];
double G[N][N];
int cnt = 2;
pos P[N];

double walkTime(int a, int b)
{
    double x = P[a].x-P[b].x;
    double y = P[a].y-P[b].y;
    x = x*x;
    y = y*y;
    return sqrt(x+y)/10;
}

double subTime(int a, int b)
{
    double x = P[a].x-P[b].x;
    double y = P[a].y-P[b].y;
    x = x*x;
    y = y*y;
    return sqrt(x+y)/40;
}

void dijkstra()
{
    for(int i=0; i<=N; i++)
        sd[i] = INF;
    priority_queue<node> q;
    node fro, next;
    node beg(1,0);
    q.push(beg);
    sd[1] = 0;

    while(!q.empty())
    {
        fro = q.top();
        q.pop();
        if(!vis[fro.x])
        {
            vis[fro.x] = 1;
            for(int i=1; i<=cnt; i++)
            {
                if(!vis[i] && sd[i]>sd[fro.x]+G[fro.x][i])
                {
                    sd[i] = sd[fro.x]+G[fro.x][i];
                    q.push(node(i, sd[i]));
                }
            }
        }
    }
}

int main()
{
    IOS
    int a, b;
    cin>>a>>b;
    P[1].x = a/1000.0;
    P[1].y = b/1000.0;
    cin>>a>>b;
    P[2].x = a/1000.0;
    P[2].y = b/1000.0;

    while(cin>>a>>b)
    {
        if(a==-2&&b==-2)
            break;
        P[++cnt].x = a/1000.0;
        P[cnt].y = b/1000.0;
        cin>>a>>b;
        while(1)
        {
            P[++cnt].x = a/1000.0;
            P[cnt].y = b/1000.0;
            G[cnt-1][cnt] = subTime(cnt-1,cnt);
            G[cnt][cnt-1] = G[cnt-1][cnt];
            cin>>a>>b;
            if(a==-1 && b==-1)
                break;
        }
    }

    for(int j=1; j<=cnt; j++)
        for(int k=1; k<=cnt; k++)
            if(j!=k && G[j][k]==0)
            {
                G[j][k] = walkTime(j, k);
                G[k][j] = G[j][k];
            }

    dijkstra();
    sd[2]*=60;
    int ans = (int)(sd[2]+0.5);
    cout<<ans<<endl;

    return 0;
}
