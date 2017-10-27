#include<iostream>
#include<algorithm>

using namespace std;

string str[105];

bool cmp(const string &a,const string &b)
{
	return a+b<b+a;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int num;
		cin>>num;
		for(int i=0;i<num;i++)
		{
			cin>>str[i];
		}
		sort(str,str+num,cmp);
		for(int i=0;i<num;i++)
		{
			cout<<str[i];
		}
		cout<<endl;
	}
}
