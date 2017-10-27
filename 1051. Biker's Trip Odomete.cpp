#include <bits/stdc++.h>

using namespace std;

const double Pi = 3.1415927;
const int Mile = 5280;
const int foot = 12;
const int Min_H = 60;

int main()
{
	double perimeter=0;
	float diameter,time;
	int revolution;
	double distance=0;
	double speed = 0;
	int Case = 0;
	while(cin>>diameter>>revolution>>time && revolution)
	{
		Case++;
		perimeter=diameter*Pi;
		distance=perimeter*1.0*revolution/(Mile*foot);
		speed = distance*(1.0*Min_H*Min_H)/time;

		printf("Trip #%d: %.2lf %.2lf\n", Case,distance,speed);
	}
}