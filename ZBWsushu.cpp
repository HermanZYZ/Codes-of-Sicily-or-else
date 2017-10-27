#include<iostream>

using namespace std;
int main()
{
	int x,y,i,e,n;
	while(cin >> x >> y)
	{
		if(x==0&&y==0) break;
		i = x;
		e = 0;
		for(;i<=y;i++)
		{
			n = i*i+i+41;
			int t=2,j=0;
			for(;t<n;t++)
			{
				if(n%t==0) break;
				else j+=1;
			}
			if(j==n-2) e+=1;
			
			j = 0;
			t = 2;
		}
		if(e==y-x+1) cout << "OK" << endl;
		else cout << "Sorry" << endl;
	}
	
	return 0;
}

