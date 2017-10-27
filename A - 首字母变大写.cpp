#include<iostream>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<cstdio>
#include<cstring> 
using namespace std;
int main()
{
	string s;
	int len;
	while(getline(cin,s,'\n'))
	{
		len=s.size();
		for(int i=0;i<len;i++)
		{
			if(i==0)
				s[i]=s[i]-'a'+'A';
			if(s[i]==' ')
			{
				s[i+1]=s[i+1]-'a'+'A';
			}
		}
		cout<<s<<endl;
	}
	return 0;
}
