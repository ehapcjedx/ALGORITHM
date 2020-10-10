#include <iostream>
 #include <algorithm>
 #define INF 0x7fffffff
 using namespace std;

 int n;
 int a[501][501], b[501][501], c[501][501], d[501][501], k[501];

 int check(int s, int i)
 {
 	int x1=a[s][i], x2=a[s][i];
 	int s1=d[s][i], s2=d[s][i+1];
 	x1 = c[s][i]*x1+b[s][i];
 	x2 = c[s][i+1]*x2+b[s][i+1];

 	while(s1!=n)
 	{
 		int next = lower_bound(a[s1],a[s1]+k[s1],x1)-a[s1];
 		x1 = c[s1][next]*x1+b[s1][next];
 		s1 = d[s1][next];
 	}

 	while(s2!=n)
 	{
 		int next = lower_bound(a[s2],a[s2]+k[s2],x2)-a[s2];
 		x2 = c[s2][next]*x2+b[s2][next];
 		s2 = d[s2][next];
 	}

 	if(x1==x2)
 		return 1;
 	else
 		return 0;
 }



 int main() {

 	int T;
 	cin>>T;

 	for(int cases=0; cases<T; cases++)
 	{
 		int ans = 1;
 		cin>>n;
 		for(int i=1; i<n; i++)
 		{
 			cin>>k[i];
 			for(int j=0; j<k[i]; j++)
 			{
 				cin>>c[i][0]>>b[i][0];
 				cin>>d[i][0]>>a[i][0];
 			}
 			cin>>c[i][k[i]]>>b[i][k[i]]>>d[i][k[i]];
 			a[i][k[i]] = INF;
 		}

 		for(int i=1; i<n; i++)
 		{
 			if(k[i] == 0)
 				continue;
 			if(ans == 0)
 				break;
 			for(int j=0; j<k[i]; j++)
 			{
 				if(check(i, j)==0)
 				{
 					ans = 0;
 					break;
 				}	
 			}
 		}

 		if(ans == 1)
 			cout<<"Case #"<<cases+1<<": YES"<<endl;
 		else
 			cout<<"Case #"<<cases+1<<": NO"<<endl;
 	}
 	return 0;
 }
