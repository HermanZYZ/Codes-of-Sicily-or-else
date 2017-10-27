#include<iostream>

using namespace std;

int main()
{
	int num;
	while(cin>>num)
	{
		int n=0;
		while(num!=1)
		{
			if(num==3)
			{
				n+=2;
				break;
			}
			else if(num%2==0)
			{
				num/=2;
				n++;
			}
			else
			{
				num++;
				n++;
			}
		}
		cout<<n<<endl;
	}
}
