#include<iostream>
#include<iomanip>
#include<sstream>

using namespace std;

int main()
{
	char ch;
	string str,_str;
	int letters=0,words=0;
	while(cin.get(ch))
	{
		if(ch!='\n')
			letters++;
		str+=ch;
	}
	istringstream strm(str);
	while(strm>>_str)
		words++;
	cout<<"Letters: "<<letters<<endl<<"Words: "<<words<<endl;
	return 0;
	
/*	
	istringstream strm;
	string str,_str;
	int letters=0,words=0;
	while(getline(cin,str))
	{
		letters+=str.size();
		istringstream strm(str);
		while(strm >> _str)
			words++;
	}
	cout<<"Letters: "<<letters<<endl<<"Words: "<<words<<endl;
	return 0;
*/
} 
