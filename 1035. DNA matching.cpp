#include<iostream>
#include<set>

using namespace std;

int Match(int n)
{
	static char M[127];
	M['A']='T';
	M['C']='G';
	M['G']='C';
	M['T']='A';
	int pair=0;
	multiset<string> S;
	string str,ma;
	for(int i=0;i<n;i++)
	{
		cin>>str;
		ma.clear();
		for(int j=0;j<str.size();j++)
		{
			ma+=M[str[j]]; 
		}
		if(S.count(ma))
		{
			pair++;
			S.erase(S.lower_bound(ma));
		}
		else
			S.insert(str);
	}
	return pair;
} 

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		cout<<Match(n)<<endl;
	}
}
