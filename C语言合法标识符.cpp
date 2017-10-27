#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int main()
{
	int n,i=0;
	scanf("%d\n",&n);
	while(n--)
	{
     	char st[51];
	    gets(st);
		int check=1,len=0;
		if((st[0]>=65 && st[0]<=90) || st[0]==95 || (st[0]>=97 && st[0]<=122))
		{
			for(int i=0;i<strlen(st);i++)
			{
				if((st[i]>=65 && st[i]<=90) || st[i]==95 || (st[i]>=97 && st[i]<=122) || (st[i]>=48 && st[i]<=57))
				len++;
				else
				{
					cout<<"no"<<endl;
					check=0;
					break;
				}
			}
		}
		else
		{
			cout<<"no"<<endl;
			check=0;
		}
	if(check==1)
	cout<<"yes"<<endl;
     
	}
	return 0;
}
