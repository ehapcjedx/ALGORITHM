// POJ-2236
// 并查集模板题

#include <cstdio>
#include <list>
#define N 1005
using namespace std;

struct node
{
    int x, y;
};

node cpt[N];
int pre[N], n, d, d2;
list<int> repair;

bool check(const node& a, const node& b)
{
    int xx = a.x-b.x;
    int yy = a.y-b.y;
    return xx*xx+yy*yy<=d2;
}

int find(int x)
{
    if(pre[x]!=x)
        pre[x] = find(pre[x]);
    return pre[x];
}

void merge(int a, int b)
{
    int fa = find(a);
    int fb = find(b);
    if(fa!=fb)
        pre[fa] = fb; // 靠右原则
}

void connect(int a)
{
    list<int>::iterator it = repair.begin();
    pre[a] = a;
    for( ; it!=repair.end(); it++)
    {
        if(a == *it)
            continue;
        if(check(cpt[a], cpt[*it]))
            merge(a, *it);
    }
}

int main()
{
    char ch; int a, b;
    scanf("%d%d", &n, &d);
    d2 = d*d;
    for(int i=1; i<=n; i++)
        scanf("%d%d", &cpt[i].x, &cpt[i].y);
    while(scanf(" %c", &ch) != EOF) // 在%c之前加空格过滤回车
    {
        if(ch == 'O')
        {
            scanf("%d", &a);
            repair.push_back(a);
            connect(a);
        }

        if(ch == 'S')
        {
            scanf("%d%d", &a, &b);
            if(find(a)==find(b) && pre[a]*pre[b]!=0)
                printf("SUCCESS\n");
            else
                printf("FAIL\n");
        }
    }

    return 0;
}
