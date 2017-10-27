#include<iostream>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<cstdio>
using namespace std;

int main()
{
	string s;
	int n,len;
	char a,b,c; 
	cin>>a>>b>>c;
	cin>>n;		
	while(n--)
	{
		int num=0; 
		cin>>s;
		len=s.length();
		for(int i=0;i<len;i++)
		{
			if(s[i]==a || s[i]==b || s[i]==c)
				num++; 
		}
		cout<<num<<endl; 
	}
	return 0; 
} 
