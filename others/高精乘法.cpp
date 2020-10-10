//luogu p1303

#include <iostream>
#include <string>
using namespace std;

int a[2010], b[2010], res[4020];

int main()
{
    string aa, bb;
    int len, lena, lenb;
    cin>>aa;
    cin>>bb;

    if(aa=="0" || bb=="0")
    {
        cout<<"0";
        return 0;
    }

    lena = aa.size();
    lenb = bb.size();
    for(int i=0, j=lena-1; i<lena; i++, j--)
        a[i] = aa[j]-48;
    for(int i=0, j=lenb-1; i<lenb; i++, j--)
            b[i] = bb[j]-48;

    for(int i=0; i<lena; i++)
        for(int j=0; j<lenb; j++)
            res[i+j] += a[i]*b[j];
    
    if(res[lena+lenb-2]>=10)
        len = lena+lenb-1;
    else
        len = lena+lenb-2;

    for(int i=0; i<aa.size()+bb.size()-1; i++)
        if(res[i]>=10)
        {
            res[i+1] += res[i]/10;
            res[i] %= 10;
        }
    
    for(int i=len; i>=0; i--)
        cout<<res[i];


    return 0;
}
