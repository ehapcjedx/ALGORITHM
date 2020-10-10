//luogu p1255

#include <iostream>
using namespace std;

int f[5003][5003] = {0}, len;

void ways(int k)
{
    int carry = 0;
    for(int i=1; i<=len; i++)
    {
        f[k][i] = (f[k-1][i]+f[k-2][i]+carry)%10;
        if(f[k-1][i]+f[k-2][i]+carry >= 10)
            carry = 1;
        else
            carry = 0;
    }
    if(carry == 1)
    {
        len++;
        f[k][len] = 1;
    }
}

int main()
{
    int jie;
    cin>>jie;
    f[1][1] = 1;
    f[2][1] = 2;
    len = 1;

    for(int i=3; i<=jie; i++)
        ways(i);
    for(int i=len; i>0; i--)
        cout<<f[jie][i];
    cout<<endl;
    return 0;
}
