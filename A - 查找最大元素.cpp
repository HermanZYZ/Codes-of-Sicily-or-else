#include<iostream>
#include<iomanip>

using namespace std;
int main()
{
	string s,ss;
	char max;
	int arr[105];
	while(cin>>s)
	{
		max=s[0];
		for(int i=1;i<s.size();i++)
		{
			if(s[i]>=max)
			{
				max=s[i];
			}
		}
		for(int i=0;i<s.size();i++)
		{
			if(s[i]==max)
			{
				cout<<s[i]<<"(max)";
			}
			else
				cout<<s[i];
		}
		cout<<endl;
	}
}
