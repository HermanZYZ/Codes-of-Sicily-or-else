#include<stdio.h>
#include<string.h>
int main()
{
	int n;
	int a,b=0;
	scanf("%d",&n);
	while(n--)
	{
		int k=0;
		int i=0;
		scanf("%d",&a);
		if(a<0)
		{
			a=0-a;
			printf("-");
		}
			while(a%10 == 0)
			{
				a=a/10;
				i++;
			}
			int  c=strlen(char*a);
			while(c>=1)
			{
				c=c/10;
				k++;
			} 
			while(k--)
			{
				b=a%10;
				a=a/10;
				printf("%d",b);
			}
			while(i--)
				{
					printf("0");
				}
			printf("\n");
	    }
	    return 0;
    }
