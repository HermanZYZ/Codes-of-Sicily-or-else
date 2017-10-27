#include<iostream>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<cstdio>
using namespace std;
int main()
{
	int n,beg,end;
	int arr[10];
	cin>>n;
	beg=pow(10,n-1);
	end=pow(10,n);
	while(beg<end)
	{
		int i=0,a=beg,sum=0;
		for(;i<n;i++)
		{
			arr[i]=a%10;
			sum+=pow(arr[i],n);
			a/=10;
		}
		if(beg==sum)
			printf("%d\n",beg);
		beg++;
	}
	return 0;
}
