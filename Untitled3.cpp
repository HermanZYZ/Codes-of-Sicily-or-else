#include<iostream>
using namespace std;
int arr[101]; 
int main()
{
	arr[1]=0;
	arr[2]=66;
	arr[3]=131;
	arr[4]=197;
	arr[5]=262;
	arr[6]=328;
	arr[7]=393;
	arr[8]=459;
	arr[9]=524;
	arr[10]=598;
	arr[11]=655;
	
	int a,s,b,t;//输入的时间
	int n,m; //中间量 
	while(cin>>a>>s>>b>>t)
	{
		if(a==0 && b==0 && s==0 && t==0)
		break;
		if(a>b)
		{
			n=a*60+s;
			m=(b+12)*60+t; 
		} 
		else
		{
			n=a*60+s;
			m=b*60+t;
		}
	int i,k;
	for(i=1;i<12;i++)
	{
		if(n<arr[i])
		{
			i=i-1;
			break;
		}
	}
	for(k=1;k<12;k++)
	{
		if(m<arr[k])
		{
			k=k-1;
			break;
		}
	}
	cout<<i<<" "<<k<<" "<<k-i<<endl;
	}
	return 0;
	
} 
