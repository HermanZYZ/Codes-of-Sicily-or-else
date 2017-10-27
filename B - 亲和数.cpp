#include<iostream>
 using namespace std;
 #define q 600001
 int f[q];
 int main()
 {
     int m,a,b;
     for(int i=1; i<q; i++)
         for(int j=i+i; j<q; j+=i)
             f[j] += i;
     scanf("%d",&m);
     while(m--)
     {
   scanf("%d%d",&a,&b);
         if(f[a]==b&&f[b]==a)
             printf("YES\n");
         else
             printf("NO\n");
     }
     return 0;
 }
