//luogu p1308

#include <iostream>
#include <string>
using namespace std;

string aim,text;

void find_aim(const string &aim,const string &text)
{
    int count=0, start=-1, status=0;
    // status: 0 分隔符, -1 不匹配的字符, k 已匹配的字符

    for(int i=0; i<text.size(); i++)
    {
        switch(status)
        {
            case -1:
                if(text[i]<'a' || text[i]>'z')
                    status = 0;
                break;
            case 0:
                if(text[i]<'a' || text[i]>'z')
                {
                    status = 0;
                    break;
                }    
                if(text[i] == aim[status])
                    status++;
                else
                    status = -1;
                break;
            default:
                if(text[i]<'a' || text[i]>'z')
                {
                    if(status == aim.size())
                    {
                        if(count == 0)
                            start = i-status;
                        count++;
                    }
                    status = 0;
                }
                else if(text[i] == aim[status])
                    status++;
                else if(text[i] != aim[status])
                    status = -1;
        }
    }

    if(count == 0)
        cout<<"-1";
    else
        cout<<count<<" "<<start;
}

int main(){
    getline(cin,aim);
    getline(cin,text);//读取带空格的字符串
    
    for(int i=0; i<aim.size(); i++)
        if(aim[i]>='A' && aim[i]<='Z')
            aim[i] = aim[i]-'A'+'a';
    for(int i=0; i<text.size(); i++)
        if(text[i]>='A' && text[i]<='Z')
            text[i] = text[i]-'A'+'a';

    find_aim(aim,text);
    return 0;
}
