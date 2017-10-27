#include<iostream>
using namespace std;
int main()
{
	int n,len,z=0;
	cin>>n;
	while(n--)
	{
		string st;
		cin>>st;
		for(int i=0;i<st.length();i++)
		{
			if (st[i]>='0'&&st[i]<='9')
			z++;
		}
		cout<<z<<endl;
		z=0;
	}
	return 0;
}
