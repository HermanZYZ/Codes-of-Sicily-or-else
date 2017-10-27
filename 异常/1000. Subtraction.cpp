#include<iostream>
#include <stdexcept>
using namespace std;

int calc(int a, int b) throw(logic_error)
{
  if (a<0) throw out_of_range("Out of range exception");
  else if (b<0) throw out_of_range("Out of range exception");
  else if (a<b) throw logic_error("Minuend smaller than subtrahend");
  return a-b;
}

void test(int a, int b)
{
	try{
		calc(a,b);
		cout<<calc(a,b)<<endl;
	}
//	catch(out_of_range a)
//	{
//		cout<<a.what()<<endl;
//	}
	catch(logic_error a)
	{
		cout<<a.what()<<endl;
	}
}

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		test(a, b);
	}
	return 0;
}
