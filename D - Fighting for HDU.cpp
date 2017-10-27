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
	int n,hdu[105],dog[105];
	while(cin>>n)
	{
		if(n==0)
			break;
		int hdus=0,dogs=0;
		for(int i=0;i<n;i++)
		{
			cin>>hdu[i];
		}
		for(int i=0;i<n;i++)
		{
			cin>>dog[i];
		}
		sort(hdu,hdu+n);
		sort(dog,dog+n);
		for(int i=0;i<n;i++)
		{
			if(hdu[i]>dog[i])
				hdus+=2;
			else if(hdu[i]==dog[i])
			{
				hdus+=1;
				dogs+=1;
			}
			else
				dogs+=2;
		}
		cout<<hdus<<" vs "<<dogs<<endl;
	}
	return 0;
}
