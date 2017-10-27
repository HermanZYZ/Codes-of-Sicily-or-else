#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
using namespace std;
int main()
{
	string s;
	while(getline(cin,s))
	{
		bool a=false;
		s+=' ';
		for(int i=0;i<s.size();i++)
		{
			if(isalpha(s[i]))
			{
				cout<<s[i];
				a=true;
			}
			else
			{
				if(a)
					cout<<endl;
				a=false;
			}
		}
		cout<<endl;
	}
	return 0;
}
