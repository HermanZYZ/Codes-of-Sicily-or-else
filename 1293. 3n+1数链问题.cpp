#include<iostream>

using namespace std;

int cmp(int i,int& count)
{
	count++;
	if(i==1)
		return 1;
	if(i%2==1)
		return cmp(3*i+1,count);
	return cmp(i/2,count);
}

int main()
{
	int i,j;
	int n=0,m=0;
	cin>>i>>j;
 	while(i<=j)
 	{
 		cmp(i,n);
 		if(n>m)
 			m=n; 
 		n=0;
 		i++;
 	}
	cout<<m<<endl;
} 
