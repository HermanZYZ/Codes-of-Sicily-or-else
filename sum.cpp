#include<iostream>
using namespace std;
int arr[100005];
int main()
{
	int T;//列数 
	cin>>T;
	int a,i=1,I=1,t,sum=0,N,max=0;
	int rl=1,rr=0;//左右界限 
	while(T--)
	{
		cin>>t;//数列 
		N=t;
		while(I<=t)
		{
			cin>>a;//数 
			if(sum<0)
			{
				sum=0;
				rl=I;//判定左界限 
			}
			else
			sum+=a;
			arr[I-1]=sum;
			++I;
		}
		max=arr[0];
		for(I=0;I<=N;I++)
		{
			if(arr[I]>max)
			max=arr[I];//判定和最大值 
			rr=I;//判定右界限 
		}
		cout<<"Case "<<i<<endl;
		cout<<max<<" "<<rl<<" "<<rr<<endl;
		++i;
		max=0;
	}
	return 0;
}
