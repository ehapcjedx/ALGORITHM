// NC15066
// Nim问题变形
// n为奇数则必可以转移至n为偶数的P情形
// n为偶数，对手的转移操作可以用新的转移操作抵消，所以等价于Nim问题

#include <iostream>
using namespace std;

int main()
{
    int n, sum, tmp;

    while(1)
    {
        cin>>n;
        sum = 0;
        if(n==0) break;
        for(int i=0; i<n; i++)
        {
            cin>>tmp;
            sum ^= tmp;
        }
        if(n&1 || sum)
            cout<<"Win"<<endl;
        else
            cout<<"Lose"<<endl;
    }

    return 0;
}