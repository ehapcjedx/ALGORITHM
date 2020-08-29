//luogu p3916

#include <cstdio>
#include <vector>
using namespace std;

int M,N;
vector< vector<int> > G;
vector<int> A;

void dfs(int x,int beg)
{
    if(A[x])
        return;
    A[x] = beg;
    for(int i=0; i<G[x].size(); i++)
        dfs(G[x][i],beg);
}

int main(){
    int u,v;
    scanf("%d%d", &N, &M);
    G.resize(N+10);
    A.resize(N+10);
    for(int i=0; i<M; i++)
    {
        scanf("%d%d", &u, &v);
        G[v].push_back(u);
    }
    for(int i=N; i; i--)
        dfs(i, i); 
    for(int i=1; i<=N; i++)
        printf("%d ", A[i]);
    printf("\n");
    return 0;
}