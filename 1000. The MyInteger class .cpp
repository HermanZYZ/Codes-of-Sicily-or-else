#include<iostream>
#include<algorithm>
#include<cmath> 
#include <stdlib.h>

using namespace std;

class MyInteger
 {
   private:
     int value;
   public:
     MyInteger(int);
     int getValue()const;
     bool isEven()const;
     bool isOdd()const;
     bool isPrime()const;
     static bool isEven(int);
     static bool isOdd(int);
     static bool isPrime(int);
     static bool isEven(const MyInteger&);
     static bool isOdd(const MyInteger&);
     static bool isPrime(const MyInteger&);
     bool equals(int)const;
     bool equals(const MyInteger&)const;
     static int parseInt(const string&);
 };
 
 MyInteger::MyInteger(int value)
 {
 	this -> value = value;
 }
 
int MyInteger::getValue()const
{
	return value;
}

bool MyInteger::isEven()const
{
	if(value%2 == 0) return 1;
	
	return 0;
}

bool MyInteger::isOdd()const
{
	if(value%2 != 0) return 1;
	
	return 0;
}

bool MyInteger::isPrime()const
{
	if(value<2)	return 0;
	if(value==2) return 1;
	for(int i=2;i<=sqrt(value)+1;i++)
	{
		if(value%i==0)	return 0;
	}
	return 1;
}

bool MyInteger::isEven(int val)
{
	if(val%2 == 0) return 1;
	
	return 0;
}

bool MyInteger::isOdd(int val)
{
	if(val%2 != 0) return 1;
	
	return 0;
}

bool MyInteger::isPrime(int val)
{
	if(val<2)	return 0;
	if(val==2)  return 1;
	for(int i=2;i<=sqrt(val)+1;i++)
	{
		if(val%i==0)	return 0;
	}
	return 1;
}

bool MyInteger::isEven(const MyInteger& another)
{
	if(another.value%2 == 0) return 1;
	
	return 0;
}

bool MyInteger::isOdd(const MyInteger& another)
{
	if(another.value%2 != 0) return 1;
	
	return 0;
}

bool MyInteger::isPrime(const MyInteger& another)
{
	if(another.value<2)	return 0;
	if(another.value==2) return 1;
	for(int i=2;i<=sqrt(another.value)+1;i++)
	{
		if(another.value%i==0)	return 0;
	}
	return 1;
}

bool MyInteger::equals(int val)const
{
	if(val==value)	return 1;
	return 0;
}

bool MyInteger::equals(const MyInteger& another)const
{
	if(another.value==value)	return 1;
	return 0;
}

int MyInteger::parseInt(const string& str)
{
//	int cvalue=0;
//	bool flag=0;
//	if(str[0]=='-') flag=1;
//	for(int i=1;i<str.size();i++)
//	{
//		cvalue=cvalue*10+(str[i]-'0');
//	}
//	if(flag) cvalue=0-cvalue;
//	return cvalue;
	return atoi(str.c_str());
}


int main()
{
	MyInteger a=2;
	MyInteger b=-2;
	cout<<a.isOdd()<<endl;
	cout<<a.isOdd(-1)<<endl;
	cout<<a.isEven()<<endl;
	cout<<a.isEven(-1)<<endl;
	cout<<a.isPrime()<<endl;
	cout<<a.isPrime(b)<<endl;
	cout<<a.equals(-1)<<endl;
	cout<<a.equals(b)<<endl;
	cout<<a.parseInt("-10")<<endl;
	
}
