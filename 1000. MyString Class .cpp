#include<iostream> 
#include<cstring>
#include<cassert>
using namespace std;

class MyString

{

public:

    MyString(const char*);

    MyString(int = 0, char = '\0');  //initialize size_t number of char, terminated with '\0'

    MyString(const MyString&);           //copy constructor

    ~MyString();                                          //destructor

    const char* c_str();                   //return private char*

    static int getNumberOfObjects();

private:

    char *str;

    static int numberOfObjects;             //count the number of MyString objects

};


int MyString::numberOfObjects=0;

MyString:: MyString(const char* s)
{
	str=new char[strlen(s)+1];
//	assert(str!=0);
	strcpy(str,s);
	numberOfObjects++;
}
	
MyString::MyString(int size_t, char _str)
{
	char s[size_t+1];
	memset(s,_str,size_t);
	s[size_t]='\0';
	str=new char[size_t];
//	assert(str!=0);
	strcpy(str,s);
	numberOfObjects++;
}
	
MyString::MyString(const MyString& anotherstr)
{
	str = new char[strlen(anotherstr.str)+1];
//	assert(str!=0);
	strcpy(str,anotherstr.str);
	numberOfObjects++;
}
	
MyString::~MyString()
{
	delete [] str;
	numberOfObjects--;
}
const char*MyString:: c_str() 
{
	return str;
}

int MyString::getNumberOfObjects()
{
	return numberOfObjects;
}


int main()
 {
        MyString ms1(5, 'c');
        cout << ms1.c_str() << endl;// ccccc
        MyString *ptr_ms2 = new MyString("Hello!");
     {
         MyString ms3(ms1);
     }
     cout << ptr_ms2->c_str() << endl;// Hello!
     delete ptr_ms2;
     cout << MyString::getNumberOfObjects() << endl;// 1
         return 0;
 }
