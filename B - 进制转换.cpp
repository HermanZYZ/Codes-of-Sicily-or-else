#include<iostream>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<cstdio>
#include<string>
#include<cstring> 
#include<stack>
using namespace std;

int arr[100000];
int main()
{
	int n,r;
	while(cin>>n>>r)
	{
		int j=0;
		if(n<0)
		{
			n=abs(n);
			cout<<"-";
		}
		while((n/r))
		{
			arr[j]=n%r;
			n/=r;
			j++;
		}
		arr[j]=n;
		for(int i=j;i>=0;i--)
		{
			if(arr[i]>9)
			{
				switch(arr[i])
				{
					case 10: cout<<"A";break;
					case 11: cout<<"B";break;
					case 12: cout<<"C";break;
					case 13: cout<<"D";break;
					case 14: cout<<"E";break;
					case 15: cout<<"F";break;
				}
			}
			else
				cout<<arr[i];
		}
		cout<<endl; 
		
		
	}
	return 0;
}
