#include<iostream>
using namespace std;
int main()
{
	char arr[30]={'b','d','p','q','i','o','v','w','x'};
	string str;
	while(cin>>str)
	{
		int n=0,check=0;
		if(str=="#")
		break;
		else
		{
			n=str.length();
			for(int i=0;i<n;i++)
			{
				check=0;
				for(int j=0;j<11;j++)
				{
					if(str[i]==arr[j])
					{
						check=1;
						break;
					}
				}
				if(check==0)
				break;
			} 
			if(check==0)
			cout<<"INVALID"<<endl;
			else
			{
				for(int i=n-1;i>=0;i--)
				{
					if(str[i]==arr[0])
					cout<<arr[1];
					else if(str[i]==arr[1])
					cout<<arr[0];
					else if(str[i]==arr[2])
					cout<<arr[3];
					else if(str[i]==arr[3])
					cout<<arr[2];
					else
					cout<<str[i];
				}
				cout<<endl;
			}
		}
	}
} 
