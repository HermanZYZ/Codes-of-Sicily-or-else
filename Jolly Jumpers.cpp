#include<iostream>
#include<cstdio>
using namespace std;
int arr[3005];
int main()
{
	int n,i=0,j=1;
	int a=0,b;
	int check=1;
    while(scanf("%d",&n))
    {
	while(j<=n)
	{
		b=a;
		cin>>a;
		if((a-b)>=0)
			arr[i]=a-b;//第一个没用 
		else
			arr[i]=0-(a-b);//第一个没用 
		i++;
		j++;
	}
		for(int k=1;k<n;k++)
		{
			for(i=1;i<n;i++)
			{
				if(k==arr[i])
				break;
				if(i==n-1 && k!=arr[n-1])
				{
						printf("Not jolly\n");
			            check=0;
			            break;
				}
			}
		    if(check==0)
			break;
		}
	if(check==1)
	printf("Jolly\n"); 
	check=1;
	i=0;
	j=1;
    a=0;
    }
	return 0;
}
