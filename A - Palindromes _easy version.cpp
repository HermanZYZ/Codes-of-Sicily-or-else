#include<iostream>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<cstdio>
#include<string>
#include<cstring> 
#include<stack>
#include <cstdlib> 
using namespace std;
int main()
{
	int n;
	string s;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>s;
		int len=s.size()-1;
		bool check=true;
		for(int j=0;j<s.size();j++)
		{
			if(s[j]!=s[len-j])
			{
				check=false;
				cout<<"no"<<endl;
				break;
			}
		}
		if(check)
			cout<<"yes"<<endl;
	}
}
