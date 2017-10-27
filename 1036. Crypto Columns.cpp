#include<iostream>
#include<cstring>

using namespace std;

int main()
{
	string key;
	string end="THEEND";
	while(cin>>key)
	{
		if(strcmp(key.c_str(),end.c_str())==0)
			break;
		char s[105][105];
		int t[10][2];
		for(int i=0;i<key.size();i++)
		{
			t[i][0]=(char)key[i];
			t[i][1]=i;
		}
		for(int i=0;i<key.size();i++)
		{
			for(int j=0;j<key.size();j++)
			{
				if(t[j][0]>t[i][0])
				{
					swap(t[i][0],t[j][0]);
					swap(t[i][1],t[j][1]);
				}
			}
		}
		
		string str;
		cin>>str;
		
		int k=0;
		for(int i=0;i<key.size();i++)
		{
			for(int j=0;j<(str.size()/key.size());j++)
			{
				s[j][t[i][1]]=str[k];
				k++;
			}
			
		}
		
		for(int i=0;i<(str.size()/key.size());i++)
		{
//			cout<<t[i][0]<<" "<<t[i][1]<<"* ";
			for(int j=0;j<key.size();j++)
			{
				cout<<s[i][j];
			}
		}
		cout<<endl;
	}
} 
