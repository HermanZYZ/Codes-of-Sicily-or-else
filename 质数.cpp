#include <stdio.h>
int main()
{
    int a[10001];
    int i,j,number,n;
    int f;
    a[1]=2;
    number=1;
    scanf("%d",&n);
    for(i=3;i<=n;i++)
    {
        f=1;
        for(j=1;j<=number&&a[j]*a[j]<=i;j++)
        {
            if(i%a[j]==0)
            {
                f=0;
                break;
            }
        }
        if(f)
        {
            number++;
            a[number]=i;
        }
    }
    for(j=1;j<=number;j++)
    {
    	printf("%d",a[j]);
        if(j!=number)
		printf(" ");
        else 
		printf("\n");
    }
    return 0;
}
