#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>

using namespace std;

int LCS[1005][1005];

int main()
{
	string a,b;
	while(cin>>a>>b)
	{
		memset(LCS,0,sizeof(LCS));
		for(int i=0;i<=a.size();i++)
			LCS[i][0]=0;
		for(int j=0;j<=b.size();j++)
			LCS[0][j]=0;
		for(int i=1;i<=a.size();i++)
			for(int j=1;j<=b.size();j++)
				if(a[i-1]==b[j-1])
				{
					LCS[i][j]=LCS[i-1][j-1]+1;
				}
				else
				{
					LCS[i][j]=max(LCS[i-1][j],LCS[i][j-1]);
				}
		cout<<LCS[a.size()][b.size()]<<endl;
	}
}
