#include <iostream>
#include <list>
#include <cstdio>
#include <iomanip>
#include<cstring>
using namespace std;

class Josephus
{
private:
	int n,s,m;
	
public:
	
	Josephus(int N,int S,int M)
	{
		n=N;
		s=S;
		m=M;
	}
	void print()
	{
		int arr[5005];
		for(int i=1;i<5001;i++)
			arr[i]=i;
		
		int i=0,temp=n;
		while(n)
		{
			if(!arr[s])
			{
				s++;
				if(s>temp)
					s%=temp;
			}
			else
			{
				i++;
				if(i==m)
				{
					i=0;
					cout<<arr[s]<<endl;
					arr[s]=0;
					n--;
				}
				s++;
				if(s>temp)
					s%=temp;
			}
		}
	}
};

int main()
{
	int n,s,m;
	cin>>n>>s>>m;
	Josephus myjosephus(n,s,m);
	myjosephus.print();
	
	return 0;
}
