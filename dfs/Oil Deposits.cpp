// HDU-1241
// 简单bfs

#include <iostream>
#include <string>
using namespace std;

char map[100][100];
bool vis[100][100];
int m, n; int total = 0;
struct node{
    int x, y;
    node(int a=0, int b=0):x(a), y(b) {};
    node operator+(const node& nd){
        return node(x+nd.x, y+nd.y);
    }
};
node step[8] = {node(-1,-1), node(0,-1), node(1,-1), node(-1,0),
                    node(1,0), node(-1,1), node(0,1), node(1,1)};

int dfs(node s)
{
    if(vis[s.x][s.y]==1 || map[s.x][s.y]=='*')
        return -1;

    node next;
    vis[s.x][s.y] = 1;
    for(int i=0; i<8; i++)
    {
        next = s + step[i];
        if(next.x>=0 && next.y>=0 && next.x<m && next.y<n &&
            vis[next.x][next.y]==0 && map[next.x][next.y]=='@')
            dfs(next);
    }

    return 1;
}

void clear()
{
    for(int i=0; i<m; i++)
        for(int j=0; j<n; j++)
            vis[i][j] = 0;
    m = 0;
    n = 0;
    total = 0;
}

int main()
{
    string str;

    while(1)
    {
        cin>>m>>n;
        if(m*n==0)
            break;
        for(int i=0; i<m; i++)
        {
            cin>>str;
            for(int j=0; j<n; j++)
                map[i][j] = str[j];
        }
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
            {
                int res = dfs(node(i,j));
                if(res == 1)
                    total++;
            }
        cout<<total<<endl;
        clear();
    }
    
    return 0;
}