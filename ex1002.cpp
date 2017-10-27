#include<iostream>
#include<cmath>
#include<iomanip>
#include<algorithm>
using namespace std;
int main()
{
	long long  n,x,y,maxx,maxy,minx,miny;
	cin>>n;
	cin>>x>>y;
	maxx=x;
	minx=x;
	maxy=y;
	miny=y;
	for(int i=1;i<n;i++)
	{
		cin>>x>>y;
		if(x>maxx)
			swap(maxx,x);
		if(x<minx)
			swap(minx,x);
		if(y>maxy)
			swap(maxy,y);
		if(y<miny)
			swap(miny,y);
	}
	cout<<(maxx-minx)*(maxy-miny)<<endl;
	return 0;
} 
