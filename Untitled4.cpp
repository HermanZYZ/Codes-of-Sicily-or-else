	#include<stdio.h>
int main()
{
	int a;//一个数
	int b,c,d;//百、十、个位数
	for(a=100;a<=999;a++)
	{
		b=a/100;
		c=(a-b*100)/10;
		d=a%10;
		if(a==b*b*b+c*c*c+d*d*d)
		printf("%d\n",a);
	} 
	return 0;
} 

