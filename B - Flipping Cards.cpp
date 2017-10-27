#include<iostream>
#include<map>
#include<string>

using namespace std;

int main()
{
	map<int ,int> card;
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a,b;
		cin>>a>>b;
		card.insert(pair<int,int>(a,b));
		n--;
		bool flag=false;
		while(n--)
		{
			cin>>a>>b;
			if(card[a]==b && card.find(b) != card.end())
			{
				flag=true;
			//	cout<<"impossible"<<endl;
			}
			else
			{
				card.insert(pair<int,int>(a,b));
			}
			
		}
		if(flag)
		{
			cout<<"impossible"<<endl;
		}
		else
		{
			cout<<"possible"<<endl;
		}
	}
}
