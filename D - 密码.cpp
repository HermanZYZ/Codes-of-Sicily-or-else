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
	cin>>n;
	
	while(n--)
	{
		int t=0,num=0;
		int arr[5]={0,0,0,0,0};
		string s;
		cin>>s;
		if(s.size()<8 || s.size()>16)
			cout<<"NO"<<endl;
		else
		{
		for(int i=0;i<s.size();i++)
		{
			if(s[i]>='a' && s[i]<='z')
				arr[0]++;
			else if(s[i]>='A' && s[i]<='Z')
				arr[1]++;
			else if(s[i]>='0' && s[i]<='9')
				arr[2]++;
			else
				arr[3]++;
		}
		for(int i=0;i<4;i++)
		{
			if(arr[i]!=0)
				num++;
		}
		if(num>=3)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
		}
	}
}
