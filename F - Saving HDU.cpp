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
	int prize[105],vol[105];
	int v,n,tol=0;
	while(cin>>v)
	{
		if(v==0)
			break;
		cin>>n;
		for(int i=0;i<n;i++)
		{
			cin>>prize[i];
			cin>>vol[i];
		}
//		for(int i=0;i<n;i++)
//		{
//			for(int j=i+1;j<n;j++)
//			{
//				if(prize[i]<prize[j])
//				{
//					swap(prize[i],prize[j]);
//					swap(vol[i],vol[j]);
//				}
//			}
//		}
		while(v)
		{
			int max=0,j;
			for(int i=0;i<n;i++)
			{
				if(prize[i]>max) 
				{
					max = prize[i];
					j = i;
				}
			}
			if(v>=vol[j])
			{
				tol+=prize[j]*vol[j];
				v-=vol[j];
			}
			else
			{
				tol+=prize[j]*v;
				v=0;
			}
			prize[j]=0;
		}
		cout<<tol<<endl;
		tol =0;
	}
	return 0;
}
