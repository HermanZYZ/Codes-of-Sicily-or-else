#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int main()
{
	int arr[10005],l,m;
	memset(arr,0,sizeof(arr));
	cin>>l>>m;
	for(int i=0;i<=l;i++)
		arr[i]=1;
	while(m--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=a;i<=b;i++)
			arr[i]=0;
	}
	int num=0;
	for(int i=0;i<=l;i++)
		num+=arr[i];
	cout<<num<<endl;
	return 0;
}
