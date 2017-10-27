#include<iostream>

using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		int max,cou=1;
		cin>>n;
		cin>>max;
		for(int i=1;i<n;i++)
		{
			int num;
			cin>>num;
			if(num>max)
			{
				max=num;
				cou=1;
			}
			else if(num==max)
				cou++;
			else
			{
				
			}
		}
		cout<<max<<" "<<cou<<endl;
		
	}
}
