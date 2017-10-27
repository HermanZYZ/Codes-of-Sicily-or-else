#include<iostream> 

using namespace std;

class Elements{
       private:
              int value;
              static int numberOfObjects;
       public:
              Elements();
              Elements(const int &value);//set value
              Elements(const Elements &elem);//copy constructor
              ~Elements();//descructor 
              Elements & operator=(const Elements &elem);//assignment
              Elements & operator=(const int &value);//assignment
              friend istream& operator>>(istream& is, Elements & elem);
              //input one integer, and set the value
              friend ostream& operator<<(ostream& os, const Elements & elem);
              //output one integer to ostream
              void setValue(const int &value);
              //set value
              int getValue()const;
              //get value 
              Elements & operator+=(const Elements &elem);
              Elements & operator+=(const int &value);
              Elements operator+(const Elements &elem)const;
              Elements operator+(const int &value)const;
              bool operator ==(const Elements &elem)const;
              bool operator ==(const int &value)const;
              bool operator <(const Elements &elem)const;
              bool operator <(const int &value)const;
              operator int()const;//converts Elementes to int
              static int getNumberOfObjects();//return the number of objects
};

class MyVector{
       private:
              Elements *elem;
              int _size;
       public:
              MyVector();//default constructor
              MyVector(int n);// constructor an Array of n Elements
              MyVector(const MyVector &vec);//copy constructor
              ~MyVector();//destructor
              const MyVector & operator=(const MyVector &vec);//assignment
              Elements &operator[](int i);//return the references of elem[i]
              Elements operator[](int i) const; //return the copy of elem[i]
              int size()const;//return the size
              bool operator == (const MyVector &vec)const;//judge if it is equal
              friend istream& operator>>(istream& is, MyVector & vec);
              //first input n as a _size, then input elem[0],elem[1],…,elem[n-1];
              friend ostream& operator<<(ostream& os, const MyVector & vec);
//output elem[0],elem[1],elem[2],..,elem[_size-1] in a line, separated by a
 //space. e.g  _size = 2 and elem[0]=5,elem[1]=6, you should output
              //”5 6” in a line
};
//------------------------------------------------------------------------------------------//
int Elements::numberOfObjects=0;
Elements::Elements(){
	value=0;
	numberOfObjects++;
}
Elements::Elements(const int &value){
	this->value=value;
	numberOfObjects++;
}//set value
Elements::Elements(const Elements &elem){
	value=elem.value;
	numberOfObjects++;
}//copy constructor
Elements::~Elements(){
	numberOfObjects--;
}//descructor 
Elements & Elements::operator=(const Elements &elem){
	value = elem.value;
	return *this;
}//assignment
Elements & Elements::operator=(const int &value){
	this->value = value;
	return *this;
}//assignment
istream& operator>>(istream& is, Elements & elem){
	is>>elem.value;
	return is;
}
//input one integer, and set the value
ostream& operator<<(ostream& os, const Elements & elem){
	os<<elem.value;
	return os;
}
//output one integer to ostream
void Elements::setValue(const int &value){
	this->value = value;
}//set value
int Elements::getValue()const{
	return value;
}//get value 
Elements & Elements::operator+=(const Elements &elem){
	value += elem.value;
	return *this;
}
Elements & Elements::operator+=(const int &value){
	this->value +=value;
	return *this;
}
Elements Elements::operator+(const Elements &elem)const{
	Elements ano_elem;
	ano_elem.value=value+elem.value;
	return ano_elem;
}
Elements Elements::operator+(const int &value)const{
	Elements ano_elem;
	ano_elem.value=this->value+value;
	return ano_elem;
}
bool Elements::operator ==(const Elements &elem)const{
	return value==elem.value;
}
bool Elements::operator ==(const int &value)const
{
	return this->value==value;
}
bool Elements::operator <(const Elements &elem)const{
	return value<elem.value; 
}
bool Elements::operator <(const int &value)const{
	return this->value<value;
}
Elements::operator int()const{
	return value;
}//converts Elementes to int
int Elements::getNumberOfObjects(){
	return numberOfObjects;
}
//return the number of objects
//-----------------------------------------------------------------------------------------
MyVector::MyVector(){
	_size=1;
	elem = new Elements[1];
	elem[0]=0;
}//default constructor
MyVector::MyVector(int n){
	elem = new Elements[n];
	_size=n;
}// constructor an Array of n Elements
MyVector::MyVector(const MyVector &vec){
	_size=vec._size;
	elem = new Elements[_size];
	for(int i=0;i<_size;i++)
		elem[i]=vec.elem[i];
}//copy constructor
MyVector::~MyVector(){
	delete [] elem;
}//destructor
const MyVector& MyVector::operator=(const MyVector &vec){
	if(*this == vec) return *this;//防止出现vec=vec的情况 
	_size=vec._size;
	delete [] elem;
	elem = new Elements[_size];
	for(int i=0;i<_size;i++)
		elem[i]=vec.elem[i];
	return *this;
}
//assignment
Elements &MyVector::operator[](int i){
	return elem[i];
}//return the references of elem[i]
Elements MyVector::operator[](int i) const{
	return elem[i];
//	if(i>=0 && i<=_size)
//		return elem[i];
} //return the copy of elem[i]
int MyVector::size()const{
	return _size;
}//return the size
bool MyVector::operator == (const MyVector &vec)const{
	if(_size!=vec._size) return 0;//要先比较长度 
	for(int i=0;i<_size;i++){
		if(elem[i]!=vec.elem[i])
			return 0;
	}
	return 1;
}//judge if it is equal
istream& operator>>(istream& is, MyVector & vec){
	delete [] vec.elem;
	is>>vec._size;
	vec.elem = new Elements[vec._size];
	for(int i=0;i<vec._size;i++)
		is>>vec.elem[i];
	return is;
}
//first input n as a _size, then input elem[0],elem[1],…,elem[n-1];
ostream& operator<<(ostream& os, const MyVector & vec){
	os<<vec.elem[0];
	for(int i=1;i<vec._size;i++)
		os<<" "<<vec.elem[i];
	return os;
}
//output elem[0],elem[1],elem[2],..,elem[_size-1] in a line, separated by a
//space. e.g  _size = 2 and elem[0]=5,elem[1]=6, you should output”5 6” in a line

//-------------------------------------------------------------------------------------//

Elements getSum(const MyVector &vec)
{
       Elements sum = 0;
       for(int i=0;i<vec.size();i++)
       {
              sum += vec[i];
       }
       return sum;
}

void sample()
{
       MyVector vec;
       while( cin >> vec )
       {vec=vec;
              cout << vec << endl;
              MyVector vec2 = vec;
              Elements sum = getSum(vec);
              int average = (int)sum / vec.size();
              //cout<<average<<endl;
              //cout<<vec[0]<<endl;
              for(int i=0;i<vec.size();i++)
              {
                     if( vec[i] < average )
                     {//cout<<"*"<<endl;
                            vec [i] = average;
                     }
              }
              cout << vec << endl;
              cout<<vec.size()<<"*"<<endl;
              if( vec == vec2 )
              {
                     cout << "They are equal" << endl;
              }
       }
}
int main()
{
	sample();
       if(Elements::getNumberOfObjects()!=0)
       {
              cout << "Error: occupied memory" << endl;
              cout << "Too young too simple, sometimes naive!" << endl;
       }
       return 0;
}

