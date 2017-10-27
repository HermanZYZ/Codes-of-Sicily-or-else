#include<iostream>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<cstdio>
#include<string>
#include<cstring> 
#include<stack>
using namespace std;


int main()
{
	int x[100001];
	int y[100001];
	int n;
	while(cin >> n)
	{
		if(n==0) 
			break;
		for(int i=0;i<n;i++)
		{
			cin >> x[i] >> y[i];
		}
		x[n]=x[0];
		y[n]=y[0];
		x[n+1]=x[1];
        y[n+1]=y[1];
		int area;
		bool check = true;
		for(int i=0;i<n;i++)
        {
            area=(x[i+1]-x[i])*(y[i+2]-y[i]) - (x[i+2]-x[i])*(y[i+1]-y[i]);
            if(area<0)
            {
            	check = false;
            }
        }
        if(check)
        {
        	cout << "convex" << endl;
		}
		else
		{
			cout << "concave" << endl;
		}
	}
	return 0;
}	 

