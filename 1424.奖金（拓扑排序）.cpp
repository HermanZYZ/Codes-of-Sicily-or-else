#include<iostream>
#include<vector>
#include<queue>
#include<cstring>

using namespace std;

const int MAX = 10001;
vector<int> adjacent[MAX];//邻接表
queue<int> q;
int inDegree[MAX];//所有结点的入度
int money[MAX];//比100多的部分

int main()
{
	int n,m,a,b;
	cin>>n>>m;
	int total = 100 * n;
	memset(inDegree,0,sizeof(inDegree));
	memset(money,0,sizeof(money));
	while(m--)
	{
		cin>>a>>b;
		adjacent[b].push_back(a);
		inDegree[a]++;
	}
	for(int i=1;i<=n;++i)
	{
		if(inDegree[i]==0)//root
			q.push(i); 
	}
	while(!q.empty())
	{
		a=q.front();
		q.pop();
		total+=money[a];
		n--; 
		for(int i=0;i<adjacent[a].size();++i)
		{
			inDegree[adjacent[a][i]]--;
			if(inDegree[adjacent[a][i]]==0)//入度变为0说明已经访问完这个结点
				q.push(adjacent[a][i]);
			money[adjacent[a][i]]=money[a]+1;
		} 
	}
	
	if(n==0)//所有结点都已经排序，无环
		cout<<total<<endl;
	else
		cout<<"Poor Xed"<<endl;
	return 0;
} 
