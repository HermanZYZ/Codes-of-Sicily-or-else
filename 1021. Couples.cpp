#include<iostream>
#include<stack>
#include<cstring>

using namespace std;

int couple[200001]={0},_couple[200001]={0};

int main() 
{
	int n;
	while(cin>>n && n)
	{
		memset(couple,'0',sizeof(couple));
		memset(_couple,'0',sizeof(_couple));
		int a,b;
		for(int i=0;i<n;i++)
		{
			cin>>a>>b;
			couple[a]=b;
			couple[b]=a;
		}
		stack<int> cou;
		for(int i=1;i<=2*n;i++)
		{
			if(cou.empty())
				cou.push(i);
			else if(couple[cou.top()]==i || _couple[cou.top()]==i)
				cou.pop();
			else 
				cou.push(i);
		}
		if(cou.empty())
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}
}
