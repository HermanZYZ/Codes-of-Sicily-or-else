
#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int n;
	scanf("%d\n",&n);
	while(n--)
	{
		string s,ss;
		getline(cin,s,'\n');
		for(int i=0;i<s.size();i++)
		{
			if(s[i]==' ')
			{
				cout<<ss<<" ";
				ss.clear();
			}
			else
			{
				ss=s[i]+ss;
			}
		}
		cout<<ss<<endl;
	}
		return 0;
}
