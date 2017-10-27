#include <bits/stdc++.h>

using namespace std;

int x[17]={0};
int result=0,n;

bool Able(int t)
{
	for(int i=1;i<t;i++)
		if(abs(t-i)==abs(x[t]-x[i]) || x[t]==x[i])
			return false;
	return true;
}

void Queen(int t)
{
	if(t>n)
		result++;
	else
	{
		for(int i=1;i<=n;i++)
		{
			x[t]=i;
			if(Able(t))
				Queen(t+1);
		}
	}
}

int main()
{
	while(cin>>n)
	{
		result=0;
		//num=0;
		memset(x,0,sizeof(x)); 
		//for(int i=1;i<=n;i++)
		{
			Queen(1);
		}
		cout<<result<<endl;
	}	
}