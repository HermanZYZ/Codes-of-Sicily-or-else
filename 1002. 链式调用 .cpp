#include<iostream>

using namespace std;

class Number
{
	int n;
public:
	Number(int n=0)
	{
		this -> n=n;
	}
	Number &add(int a=0)
	{
		n+=a;
		return *this;
	}
	Number &sub(int a=0)
	{
		n-=a;
		return *this;
	}
	void print()
	{
		cout<<n<<endl;
	}
};

int main()
 {
     Number n(1);
     n.add(2).sub(3).add(4);
     n.print();
     return 0;
 }
