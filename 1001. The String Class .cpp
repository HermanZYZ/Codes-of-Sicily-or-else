#include<iostream>
using namespace std;
class String {

public:

  String();             // str = ""

  String(const char*);    // str = "abc" 

  String(const String&);   // str = other_string

  String& operator=(const char *);

  String& operator=(const String&);

  String operator+(const String&);

  ~String();


  char& operator[](int i);
  char operator[](int i) const;

  int size() const;

  String& operator+=(const String&);
  String& operator+=(const char*);

  friend ostream& operator<<(ostream&, const String&);
  friend istream& operator>>(istream&, String&);
  friend bool operator==(const String& x, const char* s);
  friend bool operator==(const String& x, const String& y);
  friend bool operator!=(const String& x, const char* s);
  friend bool operator!=(const String& x, const String& y);

private:

  char *str;

};


#include<cstring>
#include<string>
#include<iomanip>
String::String()             // str = ""，不是NULL，否则遇到空str会结束程序 
{
	str = new char[2];
	str=""; 
} 

String::String(const char* string)    // str = "abc" 
{
	str = new char[strlen(string)+1];
	strcpy(str,string);
//	for(int i=0;i<strlen(string);i++)
//		str[i]+=string[i];
//	str+='\0';
} 

String::String(const String& other_string)   // str = other_string
{
	str = new char[strlen(other_string.str)+1];
	strcpy(str,other_string.str);	
} 

String& String::operator=(const char *another)
{
	str = new char[strlen(another)+1];
	strcpy(str,another);
	return *this;
//	int i_size = strlen(other);    // 
//	str = new char[i_size+1];//
//	for (int i = 0; i < i_size; i++){
//		str[i] = other[i];//
//	}
//	str[i_size] = '\0';
//	return *this;     这里不可以返回一个类类型，因为这个函数返回引用对象，自动返回*this，若return 类类型，则接收不到 
}

String& String::operator=(const String&another)
{
	str = new char[strlen(another.str)+1];
	strcpy(str,another.str);
	return *this;
}

String String::operator+(const String&another)//!!!!!
{	
	String newstr;
	newstr.str =new char[strlen(str)+strlen(another.str)+1];
	strcpy(newstr.str,str);
	strcat(newstr.str,another.str);
	return newstr;
//	String temp;                 //这里可以申请并且返回一个类类型，因为这是一个普通返回函数 
//	int size = strlen(other.str) + strlen(str);
//	temp.str = new char[size + 1];
//	int i = 0;
//	for (i; i < strlen(str); i++){
//		temp.str[i] = str[i];
//	}
//	for (i; i < size; i++){            //注意爆内存，以及内存访问的问题 
//		temp.str[i] = other.str[i];
//	}
//	temp.str[i] = '\0'; 
//	return temp;
}

String::~String()
{
	delete [] str;
}

char& String::operator[](int i)
{
	if(i>=0 && i<strlen(str))
		return str[i];
}
char String::operator[](int i) const
{
	if(i>=0 && i<strlen(str))
		return str[i];
}

int String::size() const
{
	int num=0;
	for(int i=0;str[i]!='\0';i++)
		num++;
	return num;
}

String& String::operator+=(const String&another)//!!!!!
{
	char* temp;
	temp =new char[strlen(str)+1];
	strcpy(temp,str);
	str =new char[strlen(temp)+strlen(another.str)+1];
	strcpy(str,temp);
	strcat(str,another.str);//!!!!!
//	int i = 0;
//	for (i; i < strlen(str); i++){
//		temp[i] = str[i];
//	}
//	for (i; i < tsize; i++){
//		temp[i] = other.str[i];
//	}
//	str[i] = '\0';
	delete [] temp;
	return *this;
}

String& String::operator+=(const char*another)//!!!!!
{
	char* temp;
	temp =new char[strlen(str)+1];
	strcpy(temp,str);
	str =new char[strlen(temp)+strlen(another)+1];
	strcpy(str,temp);
	strcat(str,another);
	delete [] temp;
	return *this;
}

ostream& operator<<(ostream&output, const String&another)//!!!!!
{
	output<<another.str;
	return output;
}

istream& operator>>(istream&input, String&another)//!!!!!
{ 
	another.str = new char[255];
	input>>another.str;  
	return input;
}

bool operator==(const String& x, const char* s)
{
	if(x.size() != strlen(s)) return 0;
	for(int i=0;i<strlen(s);i++)
	{
		if(x.str[i]!=s[i]) return 0;
	}
	return 1;
}

bool operator==(const String& x, const String& y)
{
	if(x.size() != y.size()) return 0;
	for(int i=0;i<x.size();i++)
	{
		if(x.str[i]!=y.str[i]) return 0;
	}
	return 1;
}

bool operator!=(const String& x, const char* s)
{
	if(x.size() != strlen(s)) return 1;
	for(int i=0;i<strlen(s);i++)
	{
		if(x.str[i]!=s[i]) return 1;
	}
	return 0;
}

bool operator!=(const String& x, const String& y)
{
	if(x.size() != y.size()) return 1;
	for(int i=0;i<x.size();i++)
	{
		if(x.str[i]!=y.str[i]) return 1;
	}
	return 0;
}





String f1(String a, String b)

{

  a[2] = 'x';

  char c = b[2];

  cout << "in f: " << a << ' ' << b << ' ' << c << '\n';

  return b;

}

 

void f2(String s, const String& r)

{

  char c1 = s[1];  // c1 = s.operator[](1).operator char()

  s[1] = 'c';    // s.operator[](1).operator=('c')

 

  char c2 = r[1];  // c2 = r.operator[](1)

//  r[1] = 'd';    // error: assignment to non-lvalue char, r.operator[](1) = 'd'

}

 

void f()

{

  String x, y, s;

  cout << "Please enter two strings\n";

  cin >> x >> y;

  cout << "x= " << x << " , y = " << y << '\n';

 

    y = f1(x,y);

    cout << y << endl;

    

    f2(x,y);

 

  cout << "s = \"" << s << "\"" << endl;

  s = "abc";

  cout << "s = \"" << s << "\"" << endl;

 

    cout << "\"" << x << "\" + \"" << y << "\" = " << "\"" << x+y << "\"\n";

  String z = x;

  if (x != z) cout << "x corrupted!\n";

  x[0] = '!';

  if (x == z) cout << "write failed!\n";

  cout << "exit: " << x << ' ' << z << '\n';  

 

    z = s;

  if (s != z) cout << "s corrupted!\n";

  s[0] = '!';

  if (s == z) cout << "write failed!\n";

  cout << "exit: " << s << ' ' << z << '\n';  

 

}

 

int main()

{

  int T;

  cin >> T;

  while (T--)

  {

    f();

  }

}

