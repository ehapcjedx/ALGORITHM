// luogu p1219
// 经典八皇后问题
// 对角线数组会大于棋盘的行数n，要开2n以上

#include <iostream>
using namespace std;

int a[30], b[30], c[30], d[30];
int total = 0, n;

void print_ans()
{
    for(int k=1; k<n; k++)
        cout<<a[k]<<" ";
    cout<<a[n]<<endl;
}

void queen(int i)
{   
    if(i > n)
    {
        total++;
        if(total <= 3)
            print_ans();
        return;
    }

    for(int j=1; j<=n; j++)
        if((!b[j]) && (!c[i+j]) && (!d[n+i-j]))
        {
            a[i] = j;
            b[j] = 1;
            c[i+j] = 1;
            d[n+i-j] = 1;
            queen(i+1);
            b[j] = 0;
            c[i+j] = 0;
            d[n+i-j] = 0;
        }
}

int main()
{
    cin>>n;
    queen(1);
    cout<<total<<endl;
    return 0;
}
