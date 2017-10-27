#include<stdio.h>
int main()
{
	int n,sum=0,i,m;
	scanf("%d",&n);
	m=n;
	long long arr[n];
	for(i=0;i<n;i++)
	{
		long long a;
		scanf("%lld",&a);
		sum=sum+a;
		arr[i]=a;
	}
	while(i--)
	{
		if(i==n-1)
		{
			printf("%lld",arr[i]);
		}
		else
		{
			printf(" %lld",arr[i]);
		}
	}
	printf("\n");
	printf("%d ",sum);
	printf("%.2lf",1.0*sum/m);
	return 0;
} 
