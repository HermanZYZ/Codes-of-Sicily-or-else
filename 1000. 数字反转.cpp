#include <bits/stdc++.h>

using namespace std;

int main()
{
	string in,out;
	cin>>in;
	if(in[0]=='-')
	{
		reverse(in.begin(),in.end());
		out+='-';
		int index=0;
		while(in[index]=='0')
			index++;
		for(;index<in.size()-1;index++)
			out+=in[index];
	}
	else
	{
		reverse(in.begin(),in.end());
		int index=0;
		while(in[index]=='0')
			index++;
		for(;index<in.size();index++)
			out+=in[index];
	}
	cout<<out<<endl;
}