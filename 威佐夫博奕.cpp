
#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
    int n,m,temp,k;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        if(n<m)
        {
            temp=n;
            n=m;
            m=temp;
        }
        k=n-m;
        n=(int)(k*(1+sqrt(5))/2.0);
        if(n==m)
         printf("0\n");
        else
         printf("1\n");
    }
    return 0;
}

