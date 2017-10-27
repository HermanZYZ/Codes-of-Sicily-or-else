#include<iostream>
#include<string>
#include<cctype>

using namespace std;

int main()
{
	string str;
	char letter;
	while(getline(cin,str))
	{
		if(str=="*")
			break;
		letter = toupper(str[0]);
		bool flag=1;
		for(int i=1;i<str.size();i++)
		{
			if(str[i] ==' ' && str[i+1] !=' ')
			{
				if(letter != toupper(str[i+1]))
				{
					cout<<"N"<<endl;
					flag=0;
					break;
				}
			}
		}
		if(flag)
		{
			cout<<"Y"<<endl;
		}
	}
}
