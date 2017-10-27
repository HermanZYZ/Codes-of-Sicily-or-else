#include<iostream>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	int n,m;
	
	while(cin>>n>>m)
	{
		int arr[100][550];
		double avem[100],aven[550];
		memset(avem, 0, sizeof(avem));
		memset(aven, 0, sizeof(aven));
		if(n==0 || m==0)
		{
			cout<<0<<endl<<endl;
		}
		else
		{
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=m;j++)
				{
					cin>>arr[i][j];
					avem[i]=avem[i]+arr[i][j];
				}
			}
			for(int i=1;i<=n;i++)
			{
				avem[i]=1.0*avem[i]/m;
				if(i==1)
					cout<<fixed<<setprecision(2)<<avem[i];
				else
					cout<<" "<<fixed<<setprecision(2)<<avem[i];
			}
			cout<<endl;
			for(int j=1;j<=m;j++)
			{
				for(int i=1;i<=n;i++)
				{
					aven[j]+=arr[i][j];
				}
				aven[j]=1.0*aven[j]/n;
				if(j==1)
					cout<<fixed<<setprecision(2)<<aven[j];
				else
					cout<<" "<<fixed<<setprecision(2)<<aven[j];
			}
			cout<<endl;
			int num=0;
		
			for(int i=1;i<=n;i++)
			{
				bool check=true;
				for(int j=1;j<=m;j++)
				{
					if(arr[i][j]<aven[j])
					{
						check=false;
						break;
					}
				}
				if(check)
					num++;
			}
			cout<<num<<endl<<endl;
	    }
	}
	return 0;
}
