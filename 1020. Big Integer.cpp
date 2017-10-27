#include <bits/stdc++.h>

using namespace std;

int num[101];

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		for(int i=0;i<n;i++)
			cin>>num[i];
		string value;
		cin>>value;
		cout<<"(";
		 for(int i=0;i<n;i++)
		 {
		 	int mod=0;
		 	for(unsigned int j=0;j<value.size();j++)
		 		mod=(mod*10+(value[j]-'0'))%num[i];
		 	if(i==0)
		 		cout<<mod;
		 	else
		 		cout<<","<<mod;
		 }
		 cout<<")"<<endl;
	}
}