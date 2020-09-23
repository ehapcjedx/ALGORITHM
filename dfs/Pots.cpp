// POJ-3414
// bfs回溯

#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

int a, b, c;
bool vis[105][105];

struct node{
    int opt, x, y;
    // 1清空A，2清空B，3装满A，4装满B，5B倒给A，6A倒给B，0初始状态
    node *pre;
    node(int o=0, int xx=0, int yy=0):opt(o), x(xx), y(yy){
        pre = NULL;
    }
    node operation(int i){// 不要变更现有的值
        int xx = x, yy = y;
        switch (i)
        {
        case 1:
            xx = 0;
            break;
        case 2:
            yy = 0;
            break;
        case 3:
            xx = a;
            break;
        case 4:
            yy = b;
            break;
        case 5:
            if(x+y<=a)
            {
                xx = x+y;
                yy = 0;
            }
            else
            {
                yy = y+x-a;
                xx = a;
            }
            break;
        case 6:
            if(x+y<=b)
            {
                yy = x+y;
                xx = 0;
            }
            else
            {
                xx = y+x-b;
                yy = b;
            }
            break;
        default:
            break;
        }
        return node(i, xx, yy);
    }
};

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
        for(int i=1; i<=6; i++)
        {
            *next = fro->operation(i);
            if(vis[next->x][next->y]==0)
            {
                vis[next->x][next->y] = 1;
                next->pre = fro;
                if(next->x==c || next->y==c)
                    return next;
                q.push(next);
                next = new node;
            }
        }
        q.pop();
    }

    return NULL;
}

int main()
{
    cin>>a>>b>>c;
    node *n = bfs();
    stack<node*> s;
    if(n == NULL)
        cout<<"impossible"<<endl;
    else
    {
        while(n->pre!=NULL)
        {
            s.push(n);
            n = n->pre;
        }
        cout<<s.size()<<endl;
        while(!s.empty())
        {
            n = s.top();
            switch (n->opt)
            {
            case 1:
                cout<<"DROP(1)"<<endl;
                break;
            case 2:
                cout<<"DROP(2)"<<endl;
                break;
            case 3:
                cout<<"FILL(1)"<<endl;
                break;
            case 4:
                cout<<"FILL(2)"<<endl;
                break;
            case 5:
                cout<<"POUR(2,1)"<<endl;
                break;
            case 6:
                cout<<"POUR(1,2)"<<endl;
                break;
            default:
                break;
            }
            s.pop();
        }
    }
    return 0;
}
