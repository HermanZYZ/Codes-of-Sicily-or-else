#include<iostream>
#include<set>

using namespace std;

int main()
{
	set<int>a,b;
	int n;
	cin>>n;
	while(n--)
	{
		int numa=0,numb=0;
		cin>>numa;
		while(numa--)
		{
			int s;
			cin>>s;
			a.insert(s);
		}
		cin>>numb;
		while(numb--)
		{
			int y;
			cin>>y;
			b.insert(y);
		}
		for(set<int>::iterator i=b.begin();i!=b.end();i++)
		{
			if(a.find(*i)!=a.end())
			{
				a.erase(a.find(*i));
			}
		}
		bool first = true;

		for (set<int>::iterator it = a.begin(); it != a.end(); it++) {
		if (!first) cout << " ";
		else first = false;
		cout << *it;
		}
		cout << endl;
		a.clear();
		b.clear();
	}
}
