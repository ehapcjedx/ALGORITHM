//luogu p1601

#include <iostream>
#include <string>
using namespace std;

int a[510], b[510], ans[510];

int main()
{
    int i, j;
    string m, n;
    cin>>m>>n;

    for(i=m.size()-1, j=1; i>=0; i--, j++)
        a[j] = (int)(m[i])-48;
    for(i=n.size()-1, j=1; i>=0; i--, j++)
        b[j] = (int)(n[i])-48;

    for(i=1; i<=max(m.size(),n.size()); i++)
    {
        ans[i] += a[i]+b[i];
        ans[i+1] += ans[i]/10;
        ans[i] = ans[i]%10;
    }
        

    if(ans[max(m.size(),n.size())+1] == 0)
        for(i=max(m.size(),n.size()); i>=1; i--)
            cout<<ans[i];
    else
        for(i=max(m.size(),n.size())+1; i>=1; i--)
            cout<<ans[i];

    return 0;
}