// POJ-3984
// 简单bfs回溯

#include <cstdio>
#include <queue>
#include <stack>
using namespace std;

int a[5][5], vis[5][5];
struct node
{
    int x, y;
    node* pre;
    node(int a=0, int b=0):x(a), y(b) {
        pre = NULL;
    };
    node operator+ (node n) {
        return node(x+n.x, y+n.y);
    }
};
node step[4] = {node(1,0), node(0,1), node(-1,0), node(0,-1)};

node* bfs()
{
    queue<node*> q;
    node *next = new node, *fro;
    node *beg = new node;
    q.push(beg);
    vis[0][0] = 1;

    while(!q.empty())
    {
        fro = q.front();
        for(int i=0; i<4; i++)
        {
            *next = *fro + step[i];
            if(next->x>=0 && next->y>=0 && next->x<5 && next->y<5 
                && vis[next->x][next->y]==0 && a[next->x][next->y]==0)
            {
                vis[next->x][next->y] = 1;
                next->pre = fro;
                if(next->x==4 && next->y==4)
                    return next;
                q.push(next);
                next = new node;
            }
        }
        q.pop();
    }

    return beg;
}

void print_ans(node* n)
{
    stack<node*> s;
    while(n!=NULL)
    {
        s.push(n);
        n = n->pre;
    }
    while(!s.empty())
    {
        node *t = s.top();
        s.pop();
        printf("(%d, %d)\n", t->x, t->y);
    }

}

int main()
{
    for(int i=0; i<5; i++)
        for(int j=0; j<5; j++)
            scanf("%d", &a[i][j]);

    node *end = bfs();
    print_ans(end);

    return 0;
}
