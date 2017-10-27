#include<iostream>

using namespace std;

int main()
{
	int y0,y1,y2,y3,y4,y5,y6;
	while(cin>>y0>>y1>>y2>>y3>>y4>>y5>>y6)
	{
		if(y0==0&&y1==0&&y2==0&&y3==0&&y4==0&&y5==0&&y6==0)
			break;
		int teachers=0,rest=0;
		teachers+=y0/20;
		rest=y0%20;
		
		int need=20-rest;
		if(y1>=need && y1!=0)
		{
			teachers++;
			y1-=need;
			
			teachers+=(y1/20);
			rest=y1%20;
		}
		else if(y1!=0 && rest>0)
		{
			teachers++;
			rest=0;
		}
		else if(rest!=0)
		{
			teachers++;
			rest=0;
		}
		else
		{
			rest=y1;
		}
		
		need=20-rest;
		if(y2>=need && y2!=0)
		{
			teachers++;
			y2-=need;
			
			teachers+=(y2/20);
			rest=y2%20;
		}
		else if(y2!=0 && rest>0)
		{
			teachers++;
			rest=0;
		}
		else if(rest!=0)
		{
			teachers++;
			rest=0;
		}
		else
		{
			rest=y2;
		}
		
		if(rest>0)
			need=20-rest;
		else
			need=25-rest;
		if(y3>=need && y3!=0)
		{
			teachers++;
			y3-=need;
			
			teachers+=(y3/25);
			rest=y3%25;
		}
		else if(y3!=0 && rest>0)
		{
			teachers++;
			rest=0;
		}
		else if(rest!=0)
		{
			teachers++;
			rest=0;
		}
		else
		{
			rest=y3;
		}
		
		need=25-rest;
		if(y4>=need && y4!=0)
		{
			teachers++;
			y4-=need;
			
			teachers+=(y4/25);
			rest=y4%25;
		}
		else if(y4!=0 && rest>0)
		{
			teachers++;
			rest=0;
		}
		else if(rest!=0)
		{
			teachers++;
			rest=0;
		}
		else
		{
			rest=y4;
		}
		
		if(rest>0)
			need=25-rest;
		else
			need=30-rest;
		if(y5>=need && y5!=0)
		{
			teachers++;
			y5-=need;
			
			teachers+=(y5/30);
			rest=y5%30;
		}
		else if(y5!=0 && rest>0)
		{
			teachers++;
			rest=0;
		}
		else if(rest!=0)
		{
			teachers++;
			rest=0;
		}
		else
		{
			rest=y5;
		}
		
		need=30-rest;
		if(y6>=need && y6!=0)
		{
			teachers++;
			y6-=need;
			
			teachers+=(y6/30);
			rest=y6%30;
		}
		else if(y6!=0 && rest>0)
		{
			teachers++;
			rest=0;
		}
		else if(rest!=0)
		{
			teachers++;
			rest=0;
		}
		else
		{
			rest=y6;
		}
		
		if(rest>0)
			teachers++;
		cout<<teachers<<endl;
	}
}
