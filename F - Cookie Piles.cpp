#include<iostream>

using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,a,d;
		int totol=0;
		cin>>n>>a>>d;
		
		for(int i=0;i<n;i++)
		{
			//a=a+d*i;
			totol+=(a+d*i);
		}
		cout<<totol<<endl;
	}
} 
