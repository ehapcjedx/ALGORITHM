// POJ-1860
// SPFA判断负环

#include <iostream>
#include <algorithm>
#include <queue>
#define N 200
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

struct edge{
    int next, to;
    double rate, comm;
};

int n, m , s, num_edge = 0;
int head[N], cnt[N];
edge e[N];
bool inq[N];
double v, money[N], mon;

void adde(int from, int to, double r, double c)
{
    e[++num_edge].next = head[from];
    e[num_edge].to = to;
    e[num_edge].rate = r;
    e[num_edge].comm = c;
    head[from] = num_edge;
}

bool spfa()
{
    memset(money, 0, sizeof(double)*N);
    queue<int> q;
    int fro, nexto;
    money[s] = v;
    cnt[s] = 0;
    q.push(s);

    while(!q.empty())
    {
        fro=q.front();
        q.pop();
        inq[fro] = 0;
        for(int i=head[fro]; i; i=e[i].next)
        {
            nexto = e[i].to;
            mon = (money[fro]-e[i].comm)*e[i].rate;
            if(money[nexto] < mon)
            {
                money[nexto] = mon;
                cnt[nexto] = cnt[fro]+1;
                if(cnt[nexto] > n)
                    return 1;
                if(!inq[nexto])
                {
                    q.push(nexto);
                    inq[nexto]=1;
                }
                    
            }
        }
    }
    return 0;
}

int main()
{
    IOS
    int a, b;
    double rab, cab, rba, cba;
    cin>>n>>m>>s>>v;
    for(int i=0; i<m; i++)
    {
        cin>>a>>b>>rab>>cab>>rba>>cba;
        adde(a, b, rab, cab);
        adde(b, a, rba, cba);
    }

    bool res = spfa();
    if(res)
        cout<<"YES\n"<<endl;
    else
        cout<<"NO\n"<<endl;
    return 0;
}
