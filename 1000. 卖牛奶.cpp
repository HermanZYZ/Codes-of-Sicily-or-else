#include <iostream>

using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int x,y,m,n;
		cin>>x>>y>>m>>n;
		int total=0;
		bool flag=0;
		while(m>=x || n>=y)
		{
			while(m>=x)
			{
				// if((x==1 && m>0) || (y==1 && n>0) || (x==2 && y==2 && m+n>2))
				// {
				// 	flag=1;
				// 	break;
				// }
				int temp;
				temp=m/x;
				m%=x;
				m+=temp;
				n+=temp;
				total+=temp;
			}
			// if(flag)
			// 	break;
			while(n>=y)
			{
				// if((x==1 && m>0) || (y==1 && n>0)|| (x==2 && y==2 && m+n>2))
				// {
				// 	flag=1;
				// 	break;
				// }
				int temp;
				temp=n/y;
				n%=y;
				m+=temp;
				n+=temp;
				total+=temp;
			}
			// if(flag)
			// 	break;
			if(m+n>=x+y)
			{
				flag=1;
				break;
			}
		}
		if(flag)
		{
			cout<<"INF"<<endl;
			continue;
		}
		cout<<total<<endl;
	}
}
