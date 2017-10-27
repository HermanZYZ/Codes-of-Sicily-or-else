#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	int n;
	cin>>n;
	bool A[10001];
	for(int i=0;i<10002;i++)
		A[i]=true;
	for(int i=2;i<=sqrt(n);i++)
	{
		if(A[i])
		{
			for(int j=i*i;j<n;j+=i)
			{
				A[j]=false;
			}
		}
	}
	for(int i=1;i<10001;i++)
		if(A[i])
			cout<<i<<endl;
}
