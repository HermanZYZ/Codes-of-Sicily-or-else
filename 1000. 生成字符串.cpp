#include <bits/stdc++.h>

using namespace std;

bool exist[1<<16];
int result;
string s;

void Count(int num,int len)
{
	if(len==s.size())
	{
		if(!exist[num])
		{
			exist[num]=true;
			result++;
		}
	}
	else if(s[len]=='?')
	{
		Count(num<<1,len+1);
		Count((num<<1)+1,len+1);
	}
	else
	{
		num=(num<<1)+s[len]-'0';
		Count(num,len+1);
	}
}

int main(int argc, char const *argv[])
{
	int m,n;
	while(cin>>m>>n && !(m==n && m==0))
	{
		memset(exist,0,sizeof(exist));
		result=0;
		for(int i=0;i<n;i++)
		{
			cin>>s;
			Count(0,0);
		}
		cout<<result<<endl;
	}
	return 0;
}
