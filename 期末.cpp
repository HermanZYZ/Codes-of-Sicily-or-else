#include<iostream>

using namespace std;
int main()
{
	string s;
	//int aa='a',bb='z';
	//cout<<aa<<" "<<bb;
	int num[100],k=0,a[]={1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,4,1,2,3,1,2,3,4};
	while(getline(cin,s))
	{
		for(int i=0;i<s.size();i++)
		{
			if(s[i]==' ')
				num[k]++;
			else
			{
				int temp=s[i]-97;
				num[k]+=a[temp];
			}
		}
		k++;
	}
	cout<<num[0];
	for(int i=1;i<k;i++)
	cout<<" "<<num[i];
} 
