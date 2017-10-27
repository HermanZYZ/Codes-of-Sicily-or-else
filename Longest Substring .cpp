#include<iostream>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<cstdio>
#include<cstring> 
using namespace std;
int main()
{
	int n;
	cin>>n;
	while(n--)
	{
		string s;
		cin>>s;
		int len=1,maxlen=0;
		int arr[55];
		
		for(int i=0;i<s.length();i++)
		{
			int j;
			memset(arr,0,sizeof(arr));
			arr[s[i]]=1;
			for(j=i+1;j<s.size();j++)
			{
				if(arr[s[j]]==0)
				{
					arr[s[j]]=1;
				}
				else 
					break;
			}
			
			if(j-i>maxlen)
			{
				maxlen=j-i;
			}
				
		}
		cout<<maxlen<<endl;
	}
	
	return 0;
}
