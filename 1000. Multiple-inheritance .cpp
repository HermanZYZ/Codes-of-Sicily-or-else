#include<iostream>

using namespace std; 


class A
 {
 public:
     A(int a0):a(a0) {}
     void showA() { cout<<a<<endl; }
 protected:
     int a;
 }; 

 

class C
 {
 public:
     C(int c0):c(c0) {}
     void showC() { cout<<c<<endl; }
 protected:
     int c;
 };

class B : public A, virtual public C
{
	public:
		B(int a0=11,int c0=22):A(a0),C(c0){}
};
