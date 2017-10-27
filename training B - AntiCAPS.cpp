#include<iostream>
#include<string>
using namespace std;
int main()
{
	string s;
	bool flag=true;
	while(getline(cin,s))
	{
		//string ss;
		//ss+=s[0];
		for(int i=0;i<s.size();i++)
		{
			if(flag)
			{
				if(s[i]>='A' && s[i]<='Z')
					flag=false;
			}
			else
			{
				if(s[i]>='A' && s[i]<='Z')
					s[i]+=('a'-'A'); 
				else if(s[i]=='.' || s[i]=='?' || s[i]=='!')
					flag=true;
			}
		}
		//ss.clear();
		cout<<s<<endl;
	}
}
