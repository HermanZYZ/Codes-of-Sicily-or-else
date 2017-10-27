#include<stdio.h>
int main()
{
	int n,a;
	int i,k,j;
	scanf("%d",&n);
	int arr1[n][n],arr2[n][n];
	for(i=1;i<=n;i++)
	{
		for(k=1;k<=n;k++)
		{
			scanf("%d",&a);
			arr1[i][k]=a; 
		}
	}
	for(k=1;k<=n;k++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%d",&a);
			arr2[k][j]=a;
		}
	}
	int arr[n][n];
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			arr[i][j]=0;
		}
	} 
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			for(k=1;k<=n;k++)
			{
				arr[i][j]=arr[i][j]+arr1[i][k]*arr2[k][j];
			}
		}
		
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(j==1)
			printf("%d",arr[i][j]);
			else if(j==n)
			printf(" %d\n",arr[i][j]);
			else
			printf(" %d",arr[i][j]);
		}
	} 
	return 0; 
} 
