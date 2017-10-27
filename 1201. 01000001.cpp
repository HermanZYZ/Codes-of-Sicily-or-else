#include<iostream>
#include<stack>
#include<cstdio>

using namespace std;

int main()
{
	int n;
	cin>>n;
	getchar();
	for(int i=1;i<=n;i++)
	{
		char a,b;
		stack<char> as,bs;
		while((a=getchar()) != ' ' && a != '\n')
			as.push(a);
		while((b=getchar()) != '\n' && b != ' ')
			bs.push(b);
		
		stack<char> result;
		int temp = 0;
		while((!as.empty() && !bs.empty()))
		{
			temp = (as.top() - '0') + (bs.top() - '0') + temp;
			as.pop();
			bs.pop();
			if(temp == 2)
			{
				result.push('0');
				temp = 1;
			}
			else if(temp == 1)
			{
				result.push('1');
				temp = 0;
			}
			else if(temp == 3)
			{
				result.push('1');
				temp = 1;
			}
			else
				result.push('0');
		}
		
		while(!as.empty())
		{
			temp = (as.top() - '0') + temp;
			as.pop();
			if(temp==2)
			{
				temp=1;
				result.push('0');
			}
			else if(temp == 1)
			{
				result.push('1');
				temp = 0;
			}
			else if(temp == 3)
			{
				result.push('1');
				temp = 1;
			}
			else
				result.push('0');
		}
		while(!bs.empty())
		{
			temp = (bs.top() - '0') + temp;
			bs.pop();
			if(temp==2)
			{
				temp=1;
				result.push('0');
			}
			else if(temp == 1)
			{
				result.push('1');
				temp = 0;
			}
			else if(temp == 3)
			{
				result.push('1');
				temp = 1;
			}
			else
				result.push('0');
		}
		if(temp == 1)
			result.push('1');
		
		cout<<i<<" ";
		while(!result.empty()&& result.top() == '0')
			result.pop();
		if(result.empty())
		{
			cout<<0<<endl;
			continue;
		}
		else
		{
			while(!result.empty())
			{
				cout<<result.top();
				result.pop();
			}
		}
		cout<<endl;
	}
} 
