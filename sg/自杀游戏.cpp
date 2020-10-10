// NC17865
// sg打表

#include <iostream>
#include <set>
#define N 100010
using namespace std;

int t, a, b;
int sg[N];

void mex(int n)
{
    set<int> s;
    s.insert(sg[n-1]);
    for(int i=a; i<=b&&i<=n; i++)
        s.insert(sg[n-i]);
    for(int i=0; i<=n; i++)
        if(s.find(i)==s.end()) {
            sg[n] = i;
            break;
        }
}

int main()
{
    cin>>t>>a>>b;
    a++;
    b++;
    for(int i=1; i<=t; i++)
        mex(i);

    if(sg[t]==0)
        cout<<"Bob"<<endl;
    else
        cout<<"Alice"<<endl;

    return 0;
}