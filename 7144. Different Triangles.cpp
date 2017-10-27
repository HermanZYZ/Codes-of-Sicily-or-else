#include <iostream>
#include <algorithm>

using namespace std;

bool Check(int a,int b,int c)
{
	if(a<b)
		swap(a,b);
	if(a<c)
		swap(a,c);
	if(b<c)
		swap(b,c);
	if(b+c>a && a-c<b && a-b<c)
		return true;
	return false;
}

int a[105];

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n; 
		cin>>n;
		for(int i=0;i<n;i++)
			cin>>a[i];

		int sum=0;
		for(int i=0;i<n;i++)
			for(int j=i+1;j<n;j++)
				for(int k=j+1;k<n;k++)
					if(Check(a[i],a[j],a[k]))
						sum++;
		cout<<sum<<endl;
	}
}