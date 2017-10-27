#include<iostream>
#include<cstring>

using namespace std;
int main()
{
	char a[100001];
	int n,t,i;
	cin >> n;
	while(n--)
	{
		cin >> a;
		int k= strlen(a);
		for(t=k-1;t>=0;t--)
		{
			if (a[t]!='0') break;
		}
		
		if(a[0]=='-')
		{
			cout << "-";
			for(i=t;i>=1;i--)
			{
				cout << a[i];
			}
			for(i=t+1;i<=k-1;i++)
			{
				cout << "0";
			}
		}
		
		else
		{
			for(i=t;i>=0;i--)
			{
				cout << a[i];
			}
			for(i=t+1;i<=k-1;i++)
			{
				cout << "0";
			}
		}
		
		cout << endl;
	}
	
	return 0;
}
