#include<iostream>
#include<queue>

using namespace std;

struct job
{
	int num;
	int pri;
	job(int a,int b)
	{
		num=a;
		pri=b;
	}
};

int main()
{
	int t;
	cin>>t;
	int priority[10]={0};
	queue<job> que;
	while(t--)
	{
		//清空容器
		while(!que.empty())
			que.pop();
		for(int i=0;i<10;i++)
			priority[i]=0;
		//开始
		int n,m;
		cin>>n>>m;
		int prio,top=0;//
		for(int i=0;i<n;i++)
		{
			cin>>prio;
			if(prio>top)
				top=prio;
			if(i==m)
				que.push(job(i,prio));
			else
				que.push(job(i,prio));
			priority[prio]++;
		}
		
		int time=0;
		while(1)
		{
			while(priority[top]==0)
				top--;
			
			job temp=que.front();
			que.pop();
			if(temp.pri==top && temp.num==m)
			{
				time++;
				priority[top]--;
				break;
			}
			else if(temp.pri==top)
			{
				time++;
				priority[top]--;
			}
			else
			{
				que.push(temp);
			}
		}
		cout<<time<<endl;
	}
}
