#include<iostream>
#include<vector>
using namespace std;

class Mod {
public:
    virtual int productMod(const vector<int>&) = 0;
};

class Mod9999:public Mod
{
	int mod;
public:
	int productMod(const vector<int>& a)
	{
		mod=1;
		for(int i=0;i<a.size();i++)
		{
			mod=(mod*(a[i]%9999))%9999;
		}
		return mod;
	}
};

int main()
{
	vector<int>a;
	a.push_back(4);
	a.push_back(3333);
	Mod9999  b;
	cout<<b.productMod(a)<<endl;
}
