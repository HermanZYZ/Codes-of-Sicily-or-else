#include<stdio.h>
int main()
{
     int a,b,c,min,i;
     scanf("%d%d%d",&a,&b,&c);
     min=a;
     if(b<min)
         min=b;
     if(c<min)
         min=c;
     for(i=min;i>=1;i--)
     {
          if((a%i==0)&&(b%i==0)&&(c%i==0))
          {
               printf("%d\n",i);
               break;
          }
     }
     return 0;
}



if(i==1)
			printf("%d",arr[i][j]);
			else if(i==n)
			printf(" %d\n",arr[i][j]);
			else
			printf(" %d",arr[i][j]);
