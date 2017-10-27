#include <bits/stdc++.h>

using namespace std;

int main()
{
	int y;
	while(cin>>y && y)
	{
		int n=1,bit = 1<< ((y - 1960)/10 + 2);
		for(double temp = 0;;n++)
		{
			temp += log(n);
			if(temp / log(2) >= bit)
				break;
		}
		cout<<n-1<<endl;
	}
}