// POJ-3279
// 状态压缩+dfs
// 重置数据不完全

#include <iostream>
#define MAX 20
using namespace std;

int m, n, steps, stepm = -1;
bool tile[MAX][MAX], temp[MAX][MAX];
bool flip[MAX][MAX], ans[MAX][MAX];

void init()
{
    for(int i=1; i<=m; i++)
        for(int j=1; j<=n; j++)
            temp[i][j] = tile[i][j];
    memset(flip, 0, 400);
    steps = 0;
}

void fliptile(int a, int b)
{
    temp[a][b]^=1;
    temp[a-1][b]^=1;
    temp[a+1][b]^=1;
    temp[a][b-1]^=1;
    temp[a][b+1]^=1;
    flip[a][b] = 1;
    steps++;
}

void dfs(int k)
{
    if(k>m)
    {
        int check = 0;
        for(int i=1; i<=n; i++)
            if(temp[m][i]==1)
                check = 1;
        if(check==1)
            return;
        else
        {
            stepm = steps;
            for(int i=1; i<=m; i++)
                for(int j=1; j<=n; j++)
                    ans[i][j] = flip[i][j];
            return;
        }
    }

    for(int i=1; i<=n; i++)
    {
        if(temp[k-1][i]==1)
        {
            fliptile(k, i);
            if(stepm!=-1 && steps>=stepm)
                return;
        }
    }
    dfs(k+1);
}

int main()
{
    cin>>m>>n;
    for(int i=1; i<=m; i++)
        for(int j=1; j<=n; j++)
            cin>>tile[i][j];

    for (int k=0; k<1<<n; k++)// 枚举第一行的2^n种情况
    {
        init();
        for (int i=0; i<n; i++)// 根据枚举得到的k翻转第一行
            if ((k>>i&1) == 1)// 注意运算优先级，<<高于==高于&
                fliptile(1,i+1);
        dfs(2);
    }

    if(stepm==-1)
        cout<<"IMPOSSIBLE"<<endl;
    else
    {
        for(int i=1; i<=m; i++)
        {
            for(int j=1; j<=n; j++)
                cout<<ans[i][j]<<" ";
            cout<<endl;
        }
    }
    // cout<<stepm<<endl;

    return 0;
}
