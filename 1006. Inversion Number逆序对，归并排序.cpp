#include <bits/stdc++.h>

using namespace std;
const int MAX=1000;
long long  result=0;
int num[1000005];

void merge(int a[],int start,int mid,int end)
{
	int *temp=(int*)malloc((end - start+1)*sizeof(int));
	int i = start;
	int j=mid +1;
	int k=0;
	while(i<=mid&&j<=end)
	{
		if(a[i]<=a[j])
		{
			temp[k++]=a[i++];
		}
		else
		{
			temp[k++]=a[j++];
			result+=mid-i+1;
		}
	}
	while(i<=mid)
		temp[k++]=a[i++];
	while(j<=end)
		temp[k++]=a[j++];
	for(i=0;i<k;i++)
		a[start+i]=temp[i];
}

void merge_sort_up2down(int a[],int start,int end)
{
	if(a==NULL || start>=end)
		return;
	int mid=(start+end)/2;
	merge_sort_up2down(a,start,mid);
	merge_sort_up2down(a,mid+1,end);
	merge(a,start,mid,end);
}

int main(int argc, char const *argv[])
{
	int n;
	while(cin>>n)
	{
		result=0;
		int i;
		for(i=0;i<n;i++)
			cin>>num[i];
		merge_sort_up2down(num,0,n-1);
		cout<<result<<endl;
	}
	return 0;
}