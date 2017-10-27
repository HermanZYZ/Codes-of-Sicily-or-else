#include<iostream>

using namespace std;

class INT
{
  int i;
public:
  int getI() { return i; }
  INT()
  {
  	
  }
  INT(int a)
  {
  	i=a;
  }
  
  int operator+(INT& a)
  {
  	int temp;
  	temp=i+a.getI();
  	return temp;
  }
  INT& operator=(int a)
  {
  	i=a;
  	return *this;
  }
  INT& operator++()//pre
  {
  	i+=1;
  	return *this;
  }
  INT operator++(int dummy)//post
  {
  	INT temp;
	temp.i=i;
  	i+=1;
  	return temp;
  }
  bool operator==(INT& a)
  {
  	return i==a.getI(); 
  }
};

ostream& operator<<(ostream& os,INT a)
  {
  	os<<a.getI();
  	return os;
  }

int main()
{
  INT a=1, b(2), c;
  c = 3;
  cout << "a = " << a << endl;
  cout << "b = " << b << endl;  
  cout << "a+b = " << a+b << endl;
  cout << "++a = " << ++a << endl;
  cout << "a++ = " << a++ << endl;
  cout << "a = " << a << endl;

  cout << "b = " << b << endl;
  cout << "c = " << c << endl;

  cout << "a == b? " << (a==b) << endl;
  cout << "a == c? " << (a==c) << endl;
}

