#include <stdio.h>
#include <string.h>
 char* i2a(char* p,int n)
 {
 	if(n==0)
 	{
 		p+='\0'; 
 		return p;
 	}
 	int i=0;
 	for(int a=n;a!=0;i++)
 	{
 		a/=10;
 	}
	p[i-1]=n%10+'0';
 	n/=10;
 	return i2a(p,n);

 }
 int main()
 {  int n; char s[20];
    scanf("%d",&n);

 //********** i2a is called here ********************
    printf("%s\n",i2a(s,n));
 //**************************************************

    return 0;
 }

