#include<iostream>

using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,m,c,p,s;
		cin>>n>>m>>c>>p>>s;
		long long total=0;
		total=m;
		if(total>=p && s*c>p)
		{
			n=n+(int)(total/p);
			total=total%p;
		}
		for(int i=1;i<=s;i++)
		{
			total+=n*c;
			if(total>=p && (s-i)*c>p)
			{
				n=n+(int)(total/p);
				total=total%p;
			}
		}
		cout<<total<<endl;
	}
} 
