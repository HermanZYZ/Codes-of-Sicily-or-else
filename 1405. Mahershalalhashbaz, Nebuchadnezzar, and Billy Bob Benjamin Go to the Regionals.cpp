#include<iostream>
#include<algorithm>

using namespace std;

int length[1005];

bool cmp(const int a,const int b)
{
	return a>b;
}

int main()
{
	int n,k,count=0;
	while(cin>>n>>k && (n && k))
	{
		string name;
		for(int i=0;i<n;i++)
		{
			cin>>name;
			length[i]=name.size();
		}
		sort(length, length+n);
		
		bool flag=true;
		int sum=0;
		for(int i=0;i<n && flag;i+=k)
		{
			sum=0;
			for(int j=i;j<i+k;j++)
			{
				sum+=length[j];
			} 
			for(int j=i;j<i+k;j++)
			{
				if( (length[j])*k >= sum-2*k && (length[j])*k <= sum+2*k)
				{
					flag = true;
				}				
				else
				{
					flag = false;
					break;
				}	
			}
		}
		if(count!=0)
			cout<<endl;
		
		count++;
		cout<<"Case "<<count<<": ";
		if(flag)
			cout<<"yes"<<endl;
		else 
			cout<<"no"<<endl;
		
	}
} 
