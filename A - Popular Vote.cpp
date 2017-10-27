#include<iostream>
#include<cstring>

using namespace std;

int main()
{
	int t;
	int a[10];
	for(int i=0;i<10;i++)
		a[i]=0;
	long long num=0;
	cin>>t;
	while(t--)
	{
		int n=0;
		bool check=false;
		cin>>n;
		for(int i=0;i<n;i++)
		{
			int temp=0;
			cin>>temp;
			a[i]+=temp;
			num+=temp;
		}
		int max=-1,flag=-1;
		for(int i=0;i<n;i++)
		{
			if(a[i]>max)
			{
				max=a[i];
				flag=i;
			}
		}
		for(int i=0;i<n;i++)
		{
			if(flag==i)
				continue;
			if(max==a[i])
			{
				check=true;
				cout<<"no winner"<<endl;
				break;
			}
		}
		
//		cout<<a[0]<<" "<<a[1]<<" "<<a[2]<<" "<<a[3]<<endl<<endl;
		
		if(check==true)
		{
			for(int i=0;i<10;i++)
				a[i]=0;
			num=0;
			continue;
		}
		if(max*2>num)
		{
			cout<<"majority winner "<<flag+1<<endl;
		}
		else if(max*2<=num)
		{
			cout<<"minority winner "<<flag+1<<endl;
		}
		for(int i=0;i<10;i++)
			a[i]=0;
		num=0;
	}
} 
