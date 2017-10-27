#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;
int main()
{
	double x1,y1,x2,y2;
	cin>>x1>>y1>>x2>>y2;
	double dis;
	const double radius=6371.01 ;
	const double pi=3.14159;
	dis= radius * acos( sin(x1*pi/180)*sin(x2*pi/180) + cos(x1*pi/180)*cos(x2*pi/180)*cos(y1*pi/180-y2*pi/180) );
	cout<<fixed<<setprecision(2)<<dis<<endl;
} 
