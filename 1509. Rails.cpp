#include<iostream>
#include<stack>
#include<algorithm>

using namespace std;

int main()
{
	int n;
	int a[1000];
	while(cin>>n && n)
	{
		stack<int>b;
		while(cin>>a[0])
		{
			if(a[0]==0)
			{
				cout<<endl;
				break;
			}
			int k=1;
			for(int i=1;i<n;i++)
			{
				cin>>a[i];
			}
			int index=0;
			for(int i=0;i<n;i++)
			{
				b.push(k);
				while(!b.empty() && b.top()==a[index])
				{
					b.pop();
					index++;
				}
				k++;
			}
			if(b.empty())
				cout<<"Yes"<<endl;
			else 
				cout<<"No"<<endl;
			while(!b.empty())
			{
				b.pop();
			}
		}
	}
	return 0;
}
