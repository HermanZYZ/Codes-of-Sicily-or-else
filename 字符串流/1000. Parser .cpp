#include <iostream>
#include <iomanip>
#include <sstream>

using namespace std;

int main()
{
	string s;
	while(cin>>s) 
	{
		istringstream is(s); 
		int n;
		double d;
		is>>n;
		if(is.eof())
			cout<<"Integer: "<<showbase<<hex<<n<<endl;
		else
		{
			is.clear();
			is.str(s);
			is>>d;
			if(is.eof())
				cout << "Double: " << fixed << setprecision(6) << d << endl;
			else
				cout << "String: " << s << endl;
		}
	}
}            

