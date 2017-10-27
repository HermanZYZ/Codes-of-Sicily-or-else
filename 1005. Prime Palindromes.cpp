#include <bits/stdc++.h>

using namespace std;

bool Prime(int n)
{
	for(int i=2;i<sqrt(n)+1;i++)
	{
		if(n%i==0)
			return false;
	}
	return true;
}

int main(int argc, const char * argv[]) 
{
	int left,right;
	int num=0;
	while(cin>>left>>right && !(left == right && left == 0))
	{
		for(int i=1;;i++)
		{
			if(i==10 && left <= 11 && 11 <= right)
				cout<<11<<endl;
			int temp=i;
			num=temp;
			temp/=10;
			while(temp)
			{
				num=num*10+temp%10;
				temp/=10;
			}
			//cout<<i<<"***"<<endl;
			if(num>right)
				break;
			if(num < left)
				continue;
			if(Prime(num))
				cout<<num<<endl;

		}
	}
}