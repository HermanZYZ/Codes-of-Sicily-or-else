#include<stdio.h>
#include<math.h>
int main()
{
    unsigned int a,b,i;
    b=0;
    i=1;
    scanf("%u",&a);
    do{
        b=a%2;
        a=a/2;
        if(b==1)
        i+=1;
    }while(a>1);
    printf("%d\n",i);
    return 0;
}

