#include<iostream>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<cstdio>
#include<cstring> 
using namespace std;
int main()
{
	int n;
	cin>>n;
	while(n--)
	{
		int ah,am,as,bh,bm,bs;
		cin>>ah>>am>>as>>bh>>bm>>bs;
		int h=0,m=am+bm,s=as+bs;
		int tmpm=0,tmph=0;
		if((as+bs)>=60)
		{
			tmpm=(as+bs)/60;
			s=(as+bs)%60;
		}
		if((am+bm+tmpm)>=60)
		{
			tmph=(am+bm+tmpm)/60;
			m=(am+bm+tmpm)%60;
		}
		h=ah+bh+tmph;
		cout<<h<<" "<<m<<" "<<s<<endl;
	}
	
	return 0;
}
