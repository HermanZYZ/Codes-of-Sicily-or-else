#include <bits/stdc++.h>

using namespace std;

bool isPrime(int n)
{
	for(int i=2;i*i<=n;i++)
		if(n%i==0)
			return false;
	return true;
}

int main()
{
	int n;
	cin>>n;
	for(int i=3;i<n;i+=2)
	{
		if(!isPrime(i))
			continue;
		long long num=pow(2,i)-1,number;
		number=num;
		bool flag=false;
		for(long long j=3;j*j<=num;j+=2)
		{
			if(num%j==0)
			{
				if(!flag)
					cout<< j;
				else 
					cout<<" * "<< j;
				num/=j;
				j=3;
				flag=1;
			}
		}
		if(flag)
			cout<<" * "<<num<<" = "<<number<<" = ( 2 ^ "<<i<<" ) - 1"<<endl;
	}
}

/*
//0
while(true)
{
	flag[0]=true;
	turn=1;
	while( (flag[1] || flag[2]) && turn != 0);
	//critical-section
	flag[0]=false;
	//remainder section
}
//1
while(true)
{
	flag[1]=true;
	turn=2;
	while( (flag[2] || flag[0]) && turn != 1);
	//critical-section
	flag[1]=false;
	//remainder section
}
//2
while(true)
{
	flag[2]=true;
	turn=0;
	while( (flag[0] || flag[1]) && turn != 0);
	//critical-section
	flag[2]=false;
	//remainder section
}
*/