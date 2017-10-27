#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	stack<int> s;
	while(cin>>n && n)
	{
		int index=0,num,number=0;
		bool flag = true;
		
		while(flag)
		{
			while(!s.empty())
				s.pop();
			s.push(1);
			number=2;
			while(index<n)
			{
				cin>>num;
				index++;
				if(num==0)
				{
					flag=false;
					break;
				}
				while(s.top()!=num && number <= n)
				{
					s.push(number);
					number++;
				}
				if(s.top()==num)
					s.pop();

				if(s.empty() && number <= n)
				{
					s.push(number);
					number++;
				}
			}
			if(!flag)
				break;
			if(s.empty())
				cout<<"Yes"<<endl;
			else
			{
				cout<<"No"<<endl;
			}
			
			index=0;
		}
		cout<<endl;
	}
}
