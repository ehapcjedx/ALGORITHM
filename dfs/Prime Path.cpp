// POJ-3126
// 素数筛+bfs
// 中间两位别忘了可以变成0

#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int prime[10005], minP[10005];
int vis[10005];
int pnum;

struct node{
    int cnt, x[4];
    node(int a=0){
        cnt = 0;
        x[0] = a/1000;
        x[1] = (a/100)%10;
        x[2] = (a/10)%10;
        x[3] = a%10;
    }
    int get(){
        return x[0]*1000+x[1]*100+x[2]*10+x[3];
    }
    node change(int i){
        node res = *this;
        res.cnt = cnt+1;
        if(i>0 && i<10)
            res.x[3] = i;
        else if(i>=10 && i<20)
            res.x[2] = i-10;
        else if(i>=20 && i<30)
            res.x[1] = i-20;
        else if(i>30 && i<40)
            res.x[0] = i-30;
        return res;
    }
    bool check(){
        int num = this->get();
        return binary_search(prime, prime+pnum, num);
    }
};

void init()
{
    for(int i=2; i<10000; i++)
    {
        if(!minP[i])
        {
            prime[pnum++] = i;
            minP[i] = i;
        }

        for(int j=0; j<pnum && i*prime[j]<10000; j++)
            {
                minP[i*prime[j]] = prime[j];
                if(i%prime[j] == 0)
                    break;
            }
    }
}

int bfs(int a, int b)
{
    if(a==b)
        return 0;

    queue<node> q;
    node next, fro;
    node beg(a);
    q.push(beg);
    for(int i=1000; i<10000; i++)
        vis[i] = 0;
    vis[beg.get()] = 1;

    while(!q.empty())
    {
        fro = q.front();
        for(int i=1; i<40; i++)
        {
            next = fro.change(i);
            if(vis[next.get()] == 0)
            {
                vis[next.get()] = 1;
                if(next.get() == b)
                    return next.cnt;
                if(next.check())
                    q.push(next);
            }
        }
        q.pop();
    }

    return -1;
}

int main()
{
    int a, b, t;
    init();

    cin>>t;
    for(int i=0; i<t; i++)
    {
        cin>>a>>b;
        int ans = bfs(a, b);
        if(ans==-1)
        {
            cout<<"Impossible"<<endl;
            continue;
        }
        cout<<ans<<endl;
    }
    
    return 0;
}
