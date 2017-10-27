#include<iostream>
using namespace std;
int main()
{
	string s,p;
	while(cin>>s>>p)
	{
		int len1=s.size(),len2=p.size();
		int i=0,z=0;
		while(i<len1)
		{
			if(s.substr(i,len2)==p)
			{
				z++;
				i+=len2;
			}
			else
			i++;
		}
		cout<<z<<endl;
	}
	return 0;
} 
