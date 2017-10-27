#include<iostream>
#include<cstdio>  
#include<cstring>  
#include<cstdlib>   
#include<cmath>  
#include<string>  
#include<algorithm>  
#include<iostream>  
#define exp 1e-10  
using namespace std;  
const int N = 100005;  
const int M = 40;  
const int inf = 100000000;  
const int mod = 2009;  
int main()  
{  
    int t,x1,y1,z1,r1,vx1,vy1,vz1,x2,y2,z2,r2,vx2,vy2,vz2,a,b,c;  
    double n,d,ans;  
    cin>>t; 
    while(t--)  
    {  
        scanf("%d%d%d%d%d%d%d",&x1,&y1,&z1,&r1,&vx1,&vy1,&vz1);  
        scanf("%d%d%d%d%d%d%d",&x2,&y2,&z2,&r2,&vx2,&vy2,&vz2);  
        b=2*((x2-x1)*(vx2-vx1)+(y2-y1)*(vy2-vy1)+(z2-z1)*(vz2-vz1));  
        a=(vx2-vx1)*(vx2-vx1)+(vy2-vy1)*(vy2-vy1)+(vz2-vz1)*(vz2-vz1);  
        c=(x2-x1)*(x2-x1)+(y2-y1)*(y2-y1)+(z2-z1)*(z2-z1);  
        if(!a)  
        {  
            puts("No collision");  
            continue;  
        }  
        n=max(1.0*(-b)/2/a,0.0);  
        d=a*n*n+b*n+c;  
        if(d<=(r1+r2)*(r1+r2)+exp)  
        {  
            if(n==0.0)  
                puts("No collision");  
            else  
            {  
                ans=(-b-sqrt(b*b-4.0*a*(c-(r1+r2)*(r1+r2))))/2/a;  
                printf("%.3f\n",max(ans,0.0));  
            }  
        }  
        else  
            puts("No collision");  
    }  
    return 0;  
}  

