#include<iostream>
#include<set>
#include<string>

using namespace std;

int main()
{
	set<string> de;
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		while(n--)
		{
			string str;
			cin>>str;
			de.insert(str);
		} 
		cout<<de.size()<<endl;
		de.clear();
	}
}
