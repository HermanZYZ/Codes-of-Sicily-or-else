#include<iostream>

using namespace std;

int seq[5005],len[5005];

int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>seq[i];
	int Max=1,al=seq[0];
	for(int i=0;i<n;i++)
	{
		len[i]=1;
		for(int j=0;j<i;j++)
		{
			if(seq[j]<=seq[i] && len[j]+1>len[i])
				len[i]=len[j]+1;
		}
		if(len[i]>Max)
		{
			Max=len[i]; 
			al=seq[i];
		}
		else if(len[i]==Max && al>seq[i])
			al=seq[i];
	}
	cout<<Max<<" "<<al<<endl;
	return 0;
}
