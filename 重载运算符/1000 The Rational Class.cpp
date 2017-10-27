#include<iostream>

using namespace std;
class Rational

{

public:

  Rational();

  Rational(long numerator, long denominator);

  long getNumerator();

  long getDenominator();

  Rational add(Rational &secondRational);

  Rational subtract(Rational &secondRational);

  Rational multiply(Rational &secondRational);

  Rational divide(Rational &secondRational);

  int compareTo(Rational &secondRational);	// ”<”: -1, “=”: 0, “>”: 1

  bool equals(Rational &secondRational);

  int intValue();

  double doubleValue();

  string toString();

 

  // Define function operators for relational operators

  bool operator<(Rational &secondRational);

  bool operator<=(Rational &secondRational);

  bool operator>(Rational &secondRational);

  bool operator>=(Rational &secondRational);

  bool operator!=(Rational &secondRational);

  bool operator==(Rational &secondRational);

 

  // Define function operators for arithmetic operators

  Rational operator+(Rational &secondRational);

  Rational operator-(Rational &secondRational);

  Rational operator*(Rational &secondRational);

  Rational operator/(Rational &secondRational);

 

  // Define function operators for shorthand operators

  Rational& operator+=(Rational &secondRational);

  Rational& operator-=(Rational &secondRational);

  Rational& operator*=(Rational &secondRational);

  Rational& operator/=(Rational &secondRational);

 

  // Define function operator [], 0 for numerator and 1 for denominator

  long& operator[](const int &index);

 

  // Define function operators for prefix ++ and --

  Rational& operator++();

  Rational& operator--();

 

  // Define function operators for postfix ++ and --

  Rational operator++(int dummy);

  Rational operator--(int dummy);

 

  // Define function operators for unary + and -

  Rational operator+();

  Rational operator-();

 

  // Define the output and input operator

  friend ostream &operator<<(ostream &stream, Rational rational);//输出的数据不用加引用 

  friend istream &operator>>(istream &stream, Rational &rational);

 

  // Define function operator for conversion

  operator double();

 

private:

  long numerator;

  long denominator;

  static long gcd(long n, long d);

};



#include<cstdlib>
#include<cstring>
#include <sstream>
Rational::Rational(){
	numerator=0;
	denominator=1;
}

Rational::Rational(long numerator, long denominator){
//	cout<<gcd(numerator,denominator)<<endl;
	this -> numerator = numerator/gcd(numerator,denominator);
	this -> denominator = denominator/gcd(numerator,denominator);
	if(this->denominator<0)
	{
		this->numerator = 0-this->numerator;
		this->denominator=0-this->denominator;
	}
}

long Rational::getNumerator(){
	return numerator;
}

long Rational::getDenominator(){
	return denominator;
}

Rational Rational::add(Rational &secondRational){
	Rational temp;
	long long num1=numerator*secondRational.denominator,num2=secondRational.numerator*denominator;
	temp.numerator = (num1+num2)/gcd(num1+num2,denominator*secondRational.denominator);
	temp.denominator = (denominator*secondRational.denominator)/gcd(num1+num2,denominator*secondRational.denominator);
	return temp;
}

Rational Rational::subtract(Rational &secondRational){
	Rational temp;
	long long num1=numerator*secondRational.denominator,num2=secondRational.numerator*denominator;
	temp.numerator = (num1-num2)/gcd(num1-num2,denominator*secondRational.denominator);
	temp.denominator = (denominator*secondRational.denominator)/gcd(num1-num2,denominator*secondRational.denominator);
	return temp;
}

Rational Rational::multiply(Rational &secondRational){
	Rational temp;
	temp.numerator=numerator*secondRational.numerator;
	temp.denominator=denominator*secondRational.denominator;
	long long num1=temp.numerator,num2=temp.denominator;
	temp.numerator/=gcd(num1,num2);
	temp.denominator/=gcd(num1,num2);
	return temp;
}

Rational Rational::divide(Rational &secondRational){
	Rational temp;
	temp.numerator=numerator*secondRational.denominator;
	temp.denominator=denominator*secondRational.numerator;
	long long num1=temp.numerator,num2=temp.denominator;
	temp.numerator/=gcd(num1,num2);
	temp.denominator/=gcd(num1,num2);
	return temp;
}

int Rational::compareTo(Rational &secondRational){
	if(numerator==secondRational.numerator && denominator==secondRational.denominator)
		return 0;
	long long num1=numerator*secondRational.denominator,num2=secondRational.numerator*denominator;
	if(num1>num2)	return 1;
	return -1;
}	// ”<”: -1, “=”: 0, “>”: 1

bool Rational::equals(Rational &secondRational){
	long long num1=numerator*secondRational.denominator,num2=secondRational.numerator*denominator;
	if(num1==num2) return 1;
	return 0;
}

int Rational::intValue(){
	return (int)numerator/denominator;
}

double Rational::doubleValue(){
	return (double)numerator/denominator;
}

string Rational::toString(){
	string str;
	stringstream tool;
	tool << numerator;
	if(!(numerator==0 || denominator==1))
		tool << '/' << denominator;
	tool >> str;
//	char temp1[15];
//	char temp2[15];
//	itoa(numerator,temp1,10);
//	str+=temp1;
//	if(!(numerator==0 || denominator==1))
//	{
//		itoa(denominator,temp2,10);
//		str+='/';
//		str+=temp2;
//	}
//	str+='\0';
	return str;
}

  // Define function operators for relational operators

bool Rational::operator<(Rational &secondRational)
{
	if((*this).compareTo(secondRational)==-1) return 1;
	return 0;
}

bool Rational::operator<=(Rational &secondRational){
	if((*this).compareTo(secondRational)==1) return 0;
	return 1;
}

bool Rational::operator>(Rational &secondRational){
	if((*this).compareTo(secondRational)==1) return 1;
	return 0;
}

bool Rational::operator>=(Rational &secondRational){
	if((*this).compareTo(secondRational)==-1) return 0;
	return 1;
}

bool Rational::operator!=(Rational &secondRational){
	return !(*this).equals(secondRational);
}

bool Rational::operator==(Rational &secondRational){
	return (*this).equals(secondRational);
}

 

  // Define function operators for arithmetic operators
//cout<<numerator<<" "<<denominator<<" ***"<<endl;
Rational Rational::operator+(Rational &secondRational){
	return (*this).add(secondRational);
}

Rational Rational::operator-(Rational &secondRational){
	return (*this).subtract(secondRational);
}

Rational Rational::operator*(Rational &secondRational){
	return (*this).multiply(secondRational);
}

Rational Rational::operator/(Rational &secondRational){
	return (*this).divide(secondRational);
}

 

  // Define function operators for shorthand operators

Rational& Rational::operator+=(Rational &secondRational){
	*this = (*this).add(secondRational);
	return *this;
}

Rational& Rational::operator-=(Rational &secondRational){
	*this = (*this).subtract(secondRational);
	return *this;
}

Rational& Rational::operator*=(Rational &secondRational){
	*this = (*this).multiply(secondRational);
	return *this;
}

Rational& Rational::operator/=(Rational &secondRational){
	*this = (*this).divide(secondRational);
	return *this;
}

 

  // Define function operator [], 0 for numerator and 1 for denominator

long& Rational::operator[](const int &index){
	if(index==0) return this->numerator;
	return this->denominator;
}

 

  // Define function operators for prefix ++ and --

Rational& Rational::operator++(){
	numerator+=denominator;
	return *this;
}

Rational& Rational::operator--(){
	numerator-=denominator;
	return *this;
}

 

  // Define function operators for postfix ++ and --

Rational Rational::operator++(int dummy){
	Rational temp;
	temp.numerator = numerator;
	temp.denominator = denominator;
	numerator+=denominator;
	return temp;
}

Rational Rational::operator--(int dummy){
	Rational temp;
	temp.numerator = numerator;
	temp.denominator = denominator;
	numerator-=denominator;
	return temp;
}

 

  // Define function operators for unary + and -

Rational Rational::operator+(){
	return *this;
}

Rational Rational::operator-(){
	Rational temp;
	temp.denominator = denominator; 
	temp.numerator=0-numerator;
	return temp;
}

 

  // Define the output and input operator

ostream &operator<<(ostream &stream, Rational rational){
	
	if(rational.numerator%rational.denominator==0)  stream<<rational.numerator/rational.denominator;
	else stream<<rational.numerator<<"/"<<rational.denominator;
	return stream;
}

istream &operator>>(istream &stream, Rational &rational){
	stream>>rational.numerator>>rational.denominator;
	return stream;
}



  // Define function operator for conversion

Rational::operator double(){
	return (double)numerator/denominator;
}

long Rational::gcd(long n, long d){
	long temp;
	if(n<0) n=-n;
	if(d<0) d=-d;
	while(d!=0)
	{
		temp=n;
		n=d;
		d=temp%n;
	}
	return n;
}


int main()

{
	int a=-1000000,b=13;
	Rational  r(a,b);
	string s=r.toString();
	cout<<s<<endl;
	cout<<-r<<endl;
	r*=r;
	cout<<+r<<endl;
	cout<<r.intValue()<<endl;
	cout<<(double)r<<endl;
	cout<<r.doubleValue()<<endl;
//   Create and initialize two rational numbers r1 and r2.

  Rational r1(3, 2);

  Rational r2(2, 3);

 Rational r10(3,-2);
 cout<<r10<<endl;
  // Test relational operators

  cout << r1 << " > " << r2 << " is " << (r1 > r2) << endl;

  cout << r1 << " >= " << r1 << " is " << (r1 >= r1) << endl; 

  cout << r1 << " < " << r2 << " is " << (r1 < r2) << endl;

  cout << r1 << " <= " << r1 << " is " << (r1 <= r1) << endl;

  cout << r1 << " == " << r2 << " is " << (r1 == r2) << endl;

  cout << r1 << " == " << r1 << " is " << (r1 == r1) << endl;

  cout << r1 << " != " << r2 << " is " << (r1 != r2) << endl;

  cout << r1 << " != " << r1 << " is " << (r1 != r1) << endl;

 

 

  // Test toString, add, substract, multiply, and divide operators

  cout << r1 << " + " << r2 << " = " << r1 + r2 << endl;

  cout << r1 << " - " << r2 << " = " << r1 - r2 << endl;

  cout << r1 << " * " << r2 << " = " << r1 * r2 << endl;

  cout << r1 << " / " << r2 << " = " << r1 / r2 << endl;

 

  // Test shorthand operators

  Rational r3(1, 2);

  r3 += r1;

  cout << "r3 is " << r3 << endl;

  r3 -= r1;

  cout << "r3 is " << r3 << endl;

  

  // Test function operator []

  Rational r4(1, 2);

  r4[0] = 3; r4[1] = 4;

  cout << "r4 is " << r4 << endl;

 

  // Test function operators for 

  // prefix ++ and --

  // postfix ++ and --

  r3 = r4++;

  cout << "r3 is " << r3 << endl;

  cout << "r4 is " << r4 << endl;

  r3 = r4--;

  cout << "r3 is " << r3 << endl;

  cout << "r4 is " << r4 << endl;

 

 

  r3 = ++r4;

  cout << "r3 is " << r3 << endl;

  cout << "r4 is " << r4 << endl;

  r3 = --r4;

  cout << "r3 is " << r3 << endl;

  cout << "r4 is " << r4 << endl;

 

  // Test function operator for conversion

  cout << "1 + " << r4 << " is " << (1 + r4) << endl;

 

 

  return 0;

}

