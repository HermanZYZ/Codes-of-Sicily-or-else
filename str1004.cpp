#include<iostream>
using namespace std;
int main()
{
	int n,z;
	string str;
	while(cin>>n)
	{
		z=0;
		if(n==0)
		break;
		while(n--)
		{
		int a,check1=0,check2=0,check3=1;
		cin>>str;
		a=str.size();
		for(int i=0;i<a;i++)
		{
			if(str[i]=='@' && i!=a-1 && i!=0 && str[i+1]!='@' && str[i+1]!='.')
			{
				check1++;
			}
		}
		for(int i=0;i<a;i++)
		{
			if(str[i]=='.' && i!=a-1 && i!=0 && str[i+1]!='@' && str[i+1]!='.')
			{
				check2=1;
			}
			if(str[i]=='.' && i==a-1)
			check2=0;
		}
		if(check1==1 && check2==1)
		{
			for(int i=0;i<a;i++)
			{
				if((str[i]>=65 && str[i]<=90) || (str[i]>=97 && str[i]<=122) || (str[i]>=48 && str[i]<=57) || str[i]=='@'|| str[i]=='.')
				{
//					check3=1;
				}
				else
				{
					check3=0;
					break;
				}
			}
			if(check3==1)
				z++;
		}
		
		}
		cout<<z<<endl;
	}
}
