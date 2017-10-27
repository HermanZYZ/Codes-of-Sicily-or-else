#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

int main()
{
	int low[4],rate[4],up[4];
	low[0]=0;
	int set=0;
	while(cin>>up[0]>>rate[0])
	{
		set++;
		cout<<"Set number "<<set<<":"<<endl;
		
		low[1]=up[0]+1;
		for(int i=1;i<3;i++)
		{
			cin>>up[i]>>rate[i];
			low[i+1]=up[i]+1; 
		} 
		up[3]=1000;
		cin>>rate[3];
		
		int lug=0;
		while(cin>>lug && lug)
		{
			int cost=0,add=0;
			for(int i=0;i<4;i++)
			{
				if(lug>=low[i] && lug<=up[i])
				{
					cost=lug*rate[i];
					add=lug;
				}
				else if(lug<low[i])
				{
					if(cost>low[i]*rate[i])
					{
						add=low[i];
						cost=min(cost,low[i]*rate[i]);
					}
				}
			}
			cout<<"Weight ("<<lug<<") has best price $"<<cost<<" (add "<<add-lug <<" pounds)"<<endl;
		}
		cout<<endl;
	}
}
