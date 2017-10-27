#include<bits/stdc++.h>

using namespace std;

struct Position
{
	int x,y;
}pos[25];

int len[25];

bool cmp(Position a,Position b)
{
	return a.x<b.x;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		memset(len,0,sizeof(len));
		int n,Max=0;
		cin>>n;
		for(int i=0;i<n;i++)
			cin>>pos[i].x>>pos[i].y;
		sort(pos,pos+n,cmp);////////////////////////////////
		for(int i=0;i<n;i++)
		{
			len[i]=1;
			for(int j=0;j<i;j++)
			{
				if(pos[j].y<pos[i].y && len[j]+1>len[i])
					len[i]=len[j]+1;
			}
			if(len[i]>Max)
			{
				Max=len[i]; 
			}
		}
		cout<<Max<<endl;
	}
}
