#include<iostream>

using namespace std;

char content[1005];
int Left[1005];
int Right[1005];
int parent[1005];


void initial()
{
	for(int i=0;i<1001;i++)
	{
		Left[i]=0;
		Right[i]=0;
		parent[i]=0;
		content[i]=' ';
	}
}

int find_parent()
{
	for(int i=1;i<1001;i++)
	{
		if(parent[i]==0 && content[i]!=' ')
			return i;
	}
	return 0;
}

void preorder(int head)
{
	if(head == 0)
		return ;
	cout<<content[head];
	preorder(Left[head]);
	preorder(Right[head]);
}

int main()
{
	int n;
	while(cin>>n)
	{
		initial();
		char c;
		int node,l,r;
		for(int i=0;i<n;i++)
		{
			cin>>node>>c>>l>>r;
			content[node]=c;
			Left[node]=l;
			Right[node]=r;
			parent[l]=node;
			parent[r]=node; 
		}
		int father=0;
		father=find_parent();
		preorder(father);
		cout<<endl;
	}
	
}
