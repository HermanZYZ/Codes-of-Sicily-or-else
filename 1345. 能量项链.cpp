#include<iostream>
#include<cstring> 

using namespace std;

int f[205][205];
int w[205];

int main()
{
	int n;
	while(cin>>n)
	{
		for(int i=0;i<n;i++)
		{
			cin>>w[i];
			w[i+n]=w[i];
		}
		int max=-1;
		memset(f,0,sizeof(f));
		for(int i=2*n-1;i>=0;i--)
			for(int j=i+2;j<2*n;j++)
			{
				max=-1;
				for(int k=i+1;k<j;k++)
				{
					if(max < f[i][k]+f[k][j]+w[i]*w[k]*w[j])
						max = f[i][k]+f[k][j]+w[i]*w[k]*w[j];
				}	
				f[i][j]=max;			
			}
		max=-1;
		for(int i=0;i<n;i++)
			if(max < f[i][i+n])
				max = f[i][i+n];
		cout<<max<<endl;
	} 
}
