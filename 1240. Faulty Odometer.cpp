#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	while (cin >> n && n)
	{
		int result=0,temp=n;
		for(int i=1;n;n/=10,i*=9)
		{
			int v=n%10;
			if(v>4)
				v--;
			result+=v*i;
		}
		cout<<temp<<": "<<result<<endl;
	}
}