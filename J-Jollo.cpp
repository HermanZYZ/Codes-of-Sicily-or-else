#include<iostream>
#include<string>
#include<cstring>
#include<cmath>
#include<algorithm>

using namespace std;

bool cmp(int a,int b)
{
	return a>b;
}

int main()
{
	int a,b,c,d,e;
	int arr[53],brr[5];
	memset(arr,0,sizeof(arr));
	memset(brr,0,sizeof(brr));
	while(cin>>a>>b>>c>>d>>e)
	{
		if(a==0)
			break;
		arr[a]=2,arr[b]=2,arr[c]=2,arr[d]=1,arr[e]=1;
		brr[1]=a,brr[2]=b,brr[3]=c,brr[4]=d,brr[0]=e;
		sort(brr,brr+5,cmp);
		if(arr[brr[0]]==1 && arr[brr[1]]==1)
		{
			for(int i=1;i<53;i++)
			{
				if(arr[i]==0)
				{
					cout<<i<<endl;
					break;
				}
			}
		}
		else if(arr[brr[0]]==1 && arr[brr[2]]==1)
		{
			for(int i=brr[3]+1;i<54;i++)
			{
				if(i==53)
					cout<<"-1"<<endl;
				else if(arr[i]==0)
				{
					cout<<i<<endl;
					break;
				}
			}
		}
		else if(arr[brr[0]]==1 && arr[brr[3]]==1)
		{
			for(int i=brr[1]+1;i<54;i++)
			{
				if(i==53)
					cout<<"-1"<<endl;
				else if(arr[i]==0)
				{
					cout<<i<<endl;
					break;
				}
			}
		}
		else if(arr[brr[0]]==1 && arr[brr[4]]==1)
		{
			for(int i=brr[1]+1;i<54;i++)
			{
				if(i==53)
					cout<<"-1"<<endl;
				else if(arr[i]==0)
				{
					cout<<i<<endl;
					break;
				}
			}
		}
		else if(arr[brr[1]]==1 && arr[brr[2]]==1)
		{
			for(int i=brr[3]+1;i<54;i++)
			{
				if(i==53)
					cout<<"-1"<<endl;
				else if(arr[i]==0)
				{
					cout<<i<<endl;
					break;
				}
			}
		}
		else 
		{
			cout<<-1<<endl;
		}
		memset(arr,0,sizeof(arr));
	}
}
