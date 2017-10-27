#include <bits/stdc++.h>

using namespace std;

const int MAX=10;
typedef struct Node//树节点
{
	bool end;
	Node* p[MAX];
}*T;

// T NewNode()
// {
// 	T k = new T;
// 	k->end=0;
// 	memset(k->p,0,sizeof(k->p));
// 	return k;
// }

bool Insert(string &s,T u)
{
	for(int i=0;i<s.size();i++)
	{
		int m=s[i]-'0';
		if(u->p[m])//该节点已经存在
		{
			u=u->p[m];//访问该节点的后继
			if(u->end || i==s.size()-1)//u->end = 1就是碰到了一个单词的结尾
				return 0;//说明不兼容
		}
		else//如果该节点不存在，就建立节点
		{
			T k = (T)malloc(sizeof(Node));
			k->end=0;
			memset(k->p,0,sizeof(k->p));
			u->p[m]=k;
			u=u->p[m];
		}
	}
	u->end=1;
	return 1;
}

void Destory(T u)
{
	for(int i=0;i<MAX;i++)
		if(u->p[i])
			Destory(u->p[i]);
	free(u);
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,flag=0;
		cin>>n;
		T u = (T)malloc(sizeof(Node));
		u->end=0;
		memset(u->p,0,sizeof(u->p));
		for(int i=0;i<n;i++)
		{
			string s;
			cin>>s;
			if(!flag && !Insert(s,u))
				flag=1;
		}
		if(flag)
			cout<<"NO"<<endl;
		else
			cout<<"YES"<<endl;
		Destory(u);
	}
	return 0;
}