#include<iostream>
using namespace std;
int arr[100005];
int main()
{
	int T;//���� 
	cin>>T;
	int a,i=1,I=1,t,sum=0,N,max=0;
	int rl=1,rr=0;//���ҽ��� 
	while(T--)
	{
		cin>>t;//���� 
		N=t;
		while(I<=t)
		{
			cin>>a;//�� 
			if(sum<0)
			{
				sum=0;
				rl=I;//�ж������ 
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
			max=arr[I];//�ж������ֵ 
			rr=I;//�ж��ҽ��� 
		}
		cout<<"Case "<<i<<endl;
		cout<<max<<" "<<rl<<" "<<rr<<endl;
		++i;
		max=0;
	}
	return 0;
}
