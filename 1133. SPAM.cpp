#include<iostream>
#include<cstring>

using namespace std;

int check(char c)
{
	if(c>='0' && c<='9') return 1;
	if(c>='a' && c<='z') return 2;
	if(c>='A' && c<='Z') return 2;
	if(c=='-') return 3;
	if(c=='_') return 4;
	if(c=='.') return 5;
	return 0;
}

int main()
{
	string email;
	while(getline(cin,email))
	{
		string front,back;
		for(int i=0;i<email.size();i++)
		{
			if(email[i]!='@') continue;
			int begin=i,end=i;
			if(check(email[i-1])>0 && check(email[i-1])<5)
			{
				for(int k=i-1;k>=0;k--)
				{
					if(check(email[k])==5 && check(email[k-1])==5)
						break;
					else if(check(email[k]))
					{
						front+=email[k];
					}
					else break;
				}
			}
			if(front[0]=='.')
				front.erase(front.begin());
			
			if(check(email[i+1])<5 && check(email[i+1])>0)
			{
				for(int k=i+1;k<email.size();k++)
				{
					if(check(email[k])==5 && check(email[k+1])==5)
						break;
					else if(check(email[k]))
					{
						back+=email[k];
					}
					else break;
				}
			}
			if(back[back.size()-1]=='.')
				back.erase(back.end()-1);
			
			if(!front.empty() && !back.empty())
			{
				for(int i=front.size()-1;i>=0;i--)
					cout<<front[i];
				cout<<"@"<<back<<endl;
			}
			front.clear();
			back.clear();
		}
		
	}
} 
