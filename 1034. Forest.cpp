#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct vertex
{
	int node,level;
	vertex(int a=0,int b=0)
	{
		node=a;
		level=b;
	}
};

int main()
{
	int n,m;
	bool valid=true;
	vector <int> adj[105];
	queue <vertex> q;
	int inDegree[105],width[105];
	int maxhigh=0,maxwidth=0;
	while(cin>>n && n)
	{
		//valid=true;
	
		cin>>m;
		maxhigh=0,maxwidth=0;
		for(int i=0;i<105;i++)
		{
			inDegree[i]=0;
			width[i]=0;
			adj[i].clear();
		}
		valid=(m<n) ? true:false;
		int a,b;
		while(m--)
		{
			cin>>a>>b;
			adj[a].push_back(b);
			inDegree[b]++;
		}
		for(int i=1;i<=n;i++)//find root 
		{
			if(inDegree[i]==0)
			{
				q.push(vertex(i,0));
			}
			if(inDegree[i]>1)
				valid=false;
		}
		if(!valid)
		{
			cout<<"INVALID"<<endl;
			while(!q.empty())//if no , wa
				q.pop();
			continue;
		}
		
		int count=0;
		while(!q.empty())//BFS
		{
			vertex temp=q.front();
			q.pop();
			count++;
			if(temp.level>maxhigh)
				maxhigh=temp.level;
			width[temp.level]++;
			for(int i=0;i<adj[temp.node].size();i++)
			{
				q.push(vertex(adj[temp.node][i],temp.level+1));
			}
		}
		if(count!=n)
			valid=false;
		sort(width,width+maxhigh+1);
		maxwidth=width[maxhigh];
		if(valid)
			cout<<maxhigh<<" "<<maxwidth<<endl;
		else 
			cout<<"INVALID"<<endl; 
	}
} 
