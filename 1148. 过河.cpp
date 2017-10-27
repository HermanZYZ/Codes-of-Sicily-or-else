#include<bits/stdc++.h>

using namespace std;

const int MAX = 1000001;
int l,s,t,m;
int n;
int pos[MAX];
bool flag[MAX];
int f[MAX];

int main()
{
	scanf("%d %d %d %d",&l,&s,&t,&m);
	for(int i=0;i<m;i++)
		scanf("%d",&pos[i]);
	int result=0;
	if(s==t)
	{
		result = 0;
		for(int i=0;i<m;i++)
			if(pos[i]%s==0)
				result++;
	}
	else
	{
		sort(pos,pos+m);
		n=0;
		memset(flag,0,sizeof(flag));
		memset(f,-1,sizeof(f));
		for(int i=0,pre = 0;i<m;i++)
		{
			n+=min(pos[i]-pre,100);
			flag[n]=1;
			pre=pos[i];
		}
		n+=min(l-pos[m-1],100);
		f[0]=0;
		for(int i=0;i<n;i++)
			if(f[i]>=0)
				for(int j=s;j<=t;j++)
				{
					int k=i+j;
					if(f[k]<0 || f[k]>f[i]+flag[k])
						f[k]=f[i]+flag[k];
				}
				
		result=m;
		for(int i=n;i<n+t;i++)
			result=min(result,f[i]);
	}
	cout<<result<<endl;
} 
