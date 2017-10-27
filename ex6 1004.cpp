#include<iostream>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<cstdio>
using namespace std;

string mo(string s)
{
	string re;
	int shi=0,ge=0;
	for(int i=s.size()-1;i>=0;i--)
	{
		shi=(s[i]-'0')*3+shi;
		ge=shi%10;
		shi=shi/10;
		re+=(ge+'0');
	}
	if(shi!=0)
		re+=(shi+'0');
	reverse(re.begin(),re.end());
	return re;
}
int main()
{
	int n;
	string result;
	cin>>n;
	result='3'; 
	n=n-1; 
	while(n--) 
	{
		result=mo(result);
	}
	cout<<result<<endl;
	return 0;
}
