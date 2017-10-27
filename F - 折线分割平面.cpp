#include<iostream>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<cstdio>
#include<cstring> 
using namespace std;
int main()
{
	int n;
	cin>>n;
	while(n--)
	{
		int num;
		cin>>num;
		cout<<2*num*num-num+1<<endl;
	}
	
	return 0;
}
