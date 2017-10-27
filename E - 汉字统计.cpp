#include<iostream>
#include<string> 
using namespace std;
int main()
{
	int n;
	cin>>n;
	getchar(); 
	while(n--)
	{
		string s;
		int num=0;
		getline(cin,s); 
		for(int i=0;i<s.size();i++)
		{
			if(s[i]<0)
				num++;
		}
		cout<<num/2<<endl;
	}
	return 0;
}
