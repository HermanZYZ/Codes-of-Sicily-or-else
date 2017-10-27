#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	string s;
	while(cin>>s)
	{
		string sub;
		int sublen=0,a;
		for(int i=0;i<s.size();i++)
		{
			sub+=s[i];
			a=1;
			for(int j=0;j<=s.size()-sub.size();j+=sub.size())
			{
				if(s.size()%sub.size())
				{
					a=0;
					break;
				}
				if(sub!=s.substr(j,sub.size()))
				{
					a=0;
					break;
				}
			}
			if(a)
				break;
		}
		cout<<sub<<endl;
	}
} 
