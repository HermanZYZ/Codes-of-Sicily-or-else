#include<iostream>

using namespace std;

class Person
{
	static int objectNum;
public:
	Person()
	{
		objectNum++;
	}
	~Person()
	{
		objectNum--;
	}	
	static int getObjectNum()
	{
		return objectNum;
	}
};

int Person::objectNum=0;

int main()
{
	cout<<Person::getObjectNum()<<endl;
	{
		Person a;
		cout<<Person::getObjectNum()<<endl;
	}
	cout<<Person::getObjectNum()<<endl;
	return 0;
}
