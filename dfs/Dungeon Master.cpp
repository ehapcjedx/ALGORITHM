// POJ-2251
// 三维bfs
// 多次请求别忘了重置vis记录

#include <cstdio>
#include <queue>
#include <string>
#include <iostream>
using namespace std;

char map[30][30][30];
bool vis[30][30][30];
struct node
{
    int x, y, z, time;
    node(int a=0, int b=0, int c=0):x(a), y(b), z(c) {
        time = 0;
    };
    node operator+ (node n) {
        return node(x+n.x, y+n.y, z+n.z);
    }
};
node step[6] = {node(1,0,0), node(-1,0,0), node(0,1,0), node(0,-1,0), node(0,0,1), node(0,0,-1)};

int bfs(node n, int a, int b, int c)
{
    queue<node> q;
    node next ,fro;
    q.push(n);
    vis[n.x][n.y][n.z] = 1;

    while(!q.empty())
    {
        fro = q.front();
        for(int i=0; i<6; i++)
        {
            next = fro + step[i];
            if(next.x>=0 && next.y>=0 && next.z>=0
                && next.x<a && next.y<b && next.z<c 
                && vis[next.x][next.y][next.z]==0 && map[next.x][next.y][next.z]!='#')
            {
                vis[next.x][next.y][next.z] = 1;
                next.time = fro.time+1;
                // cout<<next.x<<next.y<<next.z<<endl;
                if(map[next.x][next.y][next.z]=='E')
                    return next.time;
                q.push(next);
            }
        }
        q.pop();
    }

    return -1;
}

void clear(int a, int b, int c)
{
    for(int i=0; i<a; i++)
        for(int j=0; j<b; j++)
            for(int k=0; k<c; k++)
                vis[i][j][k] = 0;
}

int main()
{
    int L, R, C;
    string str;
    node s;
    while(1)
    {
        cin>>L>>R>>C;
        if(L*R*C == 0)
            break;
        for(int i=0; i<L; i++)
            for(int j=0; j<R; j++)
            {
                cin>>str;
                // cout<<str<<endl;
                for(int k=0; k<C; k++)
                {   
                    map[i][j][k] = str[k];
                    if(map[i][j][k] == 'S')
                        s = node(i,j,k);
                }
            }
                
        int ans = bfs(s, L, R, C);
        if(ans == -1)
            printf("Trapped!\n");
        else
            printf("Escaped in %d minute(s).\n", ans);

        clear(L, R, C);
    }
     
    return 0;
}