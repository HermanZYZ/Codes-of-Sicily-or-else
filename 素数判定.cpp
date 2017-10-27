#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
int main()
{
	int x,y;
	while(cin>>x>>y)
	{
		int i,n,check=1;
		if(x==0 && y==0)
		break;
		for(i=x;i<=y;i++)
		{
			n=i*i+i+41;
			for(int k=2;k<n;k++)
			{
				if(n%k==0)
				{
					check=0;
				}
			}
		}
	    if(check==0)
	    cout<<"Sorry"<<endl;
	    else
	    cout<<"OK"<<endl;
    }
    return 0;
}
