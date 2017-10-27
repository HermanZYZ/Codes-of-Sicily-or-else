#include<iostream>
#include<string>
#include<algorithm>
#include<cstring>
using namespace std;
void abcd(string pre,string s)
{
	if(s=="")
		cout<<pre<<endl;
	for(int i=0;i<s.size();i++)
	{
		string str=s;
		abcd(pre+s[i],str.erase(i,1));
	}
}
int main()
{
	string s,s1;
	cin>>s;
	abcd(s1,s);
}
