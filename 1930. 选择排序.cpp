#include<iostream>

using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[101];
		for(int i=0;i<n;i++)
			cin>>a[i];
		int cnt=0,index=0;
		bool flag=false;
		for(int i=0;i<n;i++)
		{
			int temp=a[i];
			for(int j=i;j<n;j++)
			{
				if(temp>a[j])
				{
					cnt++;
					temp=a[j];
					flag=true;
					index=j;
				}
			}
			if(flag)
			{
				swap(a[i],a[index]);
				flag=false;
			}
		}
		cout<<cnt<<endl;
	}
}
