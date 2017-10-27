#include<iostream>
#include<queue>

using namespace std;

int main()
{
	int l;
	cin>>l;
	while(l--)
	{
		string str;
		cin>>str;
		//priority_queue <int,vector <int>,greater <int> > que;
		priority_queue<int> que;
		for(int i=0;i<str.size();i++)
		{
			if(str[i]=='0')
			{
				while(!que.empty())
				{
					cout<<que.top();
					que.pop();
				}
				cout<<0;
			}
			else
			{
				int temp;
				temp=str[i]-'0';
				que.push(temp);
			}
		}
		while(!que.empty())
		{
			cout<<que.top();
			que.pop();
		}
		cout<<endl;
	}
}
