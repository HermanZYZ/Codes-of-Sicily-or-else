#include<iostream>
using namespace std;
int main()
{
int m,n,a;//一个数
int b,c,d;//百、十、个位数
while(cin>>m>>n)
{
	int e=0;
	for(a=m;a<=n;a++)
    {
       b=a/100;
       c=(a-b*100)/10;
       d=a%10;
       if(e==0 && a==b*b*b+c*c*c+d*d*d)
       {
	    printf("%d",a);
	    e++;
	   }
	   else if(e!=0 && a==b*b*b+c*c*c+d*d*d)
	   {
	   	printf(" %d",a);
	    e++;
	   } 
    }
    if(e==0)
	cout<<"no"; 
	cout<<endl;
} 
return 0;
}

