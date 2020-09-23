// HDU-1043
// 反向bfs打表+康托展开
// 注意有多组数据

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
#define MAX 370000
#define N 9
using namespace std;

const int FAC[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880}; // 阶乘
string path[MAX];// hash值为x的路径
string lrud = "lrud";
bool vis[MAX];
int step[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}}, temp[9];

struct node
{
    string path;// 路径
    int cant;// hash值
    int pos;
};

int cantor(int *a)
{
    int x = 0;
    for (int i=0; i<N; i++) {
        int smaller = 0;  // 在当前位之后小于其的个数
        for (int j=i+1; j<N; j++)
            if (a[j] < a[i])
                smaller++;
        x += FAC[N-1-i]*smaller; // 康托展开累加
    }
    return x;  // 康托展开值
}

void decantor(int x, int *ans)
{
    vector<int> v;  // 存放当前可选数
    // vector<int> ans;  // 所求排列组合
    for(int i=1; i<=N; i++)
        v.push_back(i);
    for(int i=N, j=0; i>=1; i--, j++)
    {
        int r = x % FAC[i-1];
        int t = x / FAC[i-1];
        x = r;
        sort(v.begin(),v.end());// 从小到大排序
        ans[j] = v[t];          // 剩余数里第t+1个数为当前位
        v.erase(v.begin()+t);   // 移除选做当前位的数
    }
}

int getx(int a)
{
    if(a%3!=0)
        return a%3;
    else
        return 3;
}

int gety(int a)
{
    if(a%3!=0)
        return a/3+1;
    else
        return a/3;
}

void bfs()
{
    memset(vis, 0, MAX);
    node beg, next, fro;
    queue<node> q;

    beg.pos = 9;
    beg.cant = 0;
    beg.path = "";
    path[0] = "";
    vis[0] = 1;
    q.push(beg);

    while(!q.empty())
    {
        fro = q.front();
        for(int i=0; i<4; i++)
        {
            int tx=getx(fro.pos)+step[i][0];
            int ty=gety(fro.pos)+step[i][1];
            if(tx>=1 && ty>=1 && tx<=3 && ty<=3)
            {
                next.pos = tx+(ty-1)*3;
                decantor(fro.cant, temp);
                swap(temp[fro.pos-1], temp[next.pos-1]);
                next.cant = cantor(temp);
                if(vis[next.cant] == 0)
                {
                    vis[next.cant] = 1;
                    next.path = lrud[i]+fro.path;
                    q.push(next);
                    path[next.cant] = next.path;
                }
            }
        }
        q.pop();
        // cout<<q.size()<<endl;
    }
}

int main()
{
    // int a[9];
    // for(int i=0; i<9; i++)
    //     a[i] = 9-i;
    // cout<<cantor(a)<<endl;

    bfs();
    int a[9], h;
    char s[9];
    while(cin>>s[0])
    {
        for(int i=1; i<9; i++)
            cin>>s[i];
        for(int i=0; i<9; i++)
            if(s[i] == 'x')
                a[i] = 9;
            else
                a[i] = s[i]-'0';
        h = cantor(a);
        if(vis[h]==0)
            cout<<"unsolvable"<<endl;
        else
            cout<<path[h]<<endl;
    }
    
    return 0;
}
