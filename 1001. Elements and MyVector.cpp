#include<iostream>
#include<cmath>
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
              //first input n as a _size, then input elem[0],elem[1],бн,elem[n-1];
              friend ostream& operator<<(ostream& os, const MyVector & vec);

//output elem[0],elem[1],elem[2],..,elem[_size-1] in a line, separated by a

//space. e.g  _size = 2 and elem[0]=5,elem[1]=6, you should output

              //"5 6" in a line

};
int Elements::numberOfObjects =0;
Elements::Elements()
{
	value=0;
	numberOfObjects++;
}
Elements::Elements(const int &value)
{
	this->value=value;
	numberOfObjects++;
}
Elements::Elements(const Elements &elem)
{
	value=elem.value;
	numberOfObjects++;
}
Elements::~Elements()
{
	numberOfObjects--;
}
Elements &Elements:: operator=(const Elements &elem)
{
	value=elem.value;
	return *this;
}
Elements & Elements::operator=(const int &value)
{
	this->value=value;
	return *this;
}
istream& operator>>(istream& is, Elements & elem)
{
	is>>elem.value;
	//elem.setValue(elem.value);
	return is;
}
             
ostream& operator<<(ostream& os, const Elements & elem)
{
	os<<elem.value;
	
	return os;
}

void Elements::setValue(const int &value)
{
	this->value=value;
}
int Elements::getValue()const
{
	return value;
}
 
Elements &Elements:: operator+=(const Elements &elem)
{
	value=value+elem.value;
}
Elements &Elements:: operator+=(const int &newvalue)
{
	value=value+newvalue;
	
}
Elements Elements::operator+(const Elements &elem)const
{
	Elements temp;
	
	temp.value=value+elem.value;
	return temp;
}
Elements Elements::operator+(const int &newvalue)const
{
	Elements temp;

	temp.value=value+newvalue;
	return temp;
}
bool Elements::operator ==(const Elements &elem)const
{
	if(value==elem.value) return true;
	else return false;
}
bool Elements::operator ==(const int &value)const
{
	if(this->value==value) return true;
	else return false;
}
bool Elements::operator<(const Elements &elem)const
{
	if(elem.value>this->value) return true;
	else return false;
}
bool Elements::operator <(const int &value)const
{
	if(this->value<value) return true;
	else return false;
}
Elements::operator int()const
{
	int temp=value;
	return temp; 
	
}
int Elements::getNumberOfObjects()
{
	return numberOfObjects;
}
MyVector::MyVector()
{
	elem=new Elements[1];
	_size=0;
}
MyVector::MyVector(int n)
{
	//delete [] elem;
	_size=n;
	elem=new Elements[n];
}
MyVector::MyVector(const MyVector &vec)
{
	//delete [] elem;
	_size=vec._size;
	elem=new Elements[vec._size];
	for(int i=0;i<_size;i++)
	{
		elem[i]=vec.elem[i];
	}
}
MyVector::~MyVector()
{
	delete [] elem;
}
const MyVector & MyVector::operator=(const MyVector &vec)
{
	delete [] elem;
	_size=vec._size;
	elem=new Elements[vec.size()];
	for(int i=0;i<_size;i++)
	{
		elem[i]=vec.elem[i];
	}
	return *this;
}
Elements &MyVector::operator[](int i)
{
	return elem[i];
}
Elements MyVector::operator[](int i) const
{
	return elem[i];
}
int MyVector::size()const
{
	return _size;
}
bool MyVector::operator == (const MyVector &vec)const
{
	bool flag=false;
	if(_size==vec._size)
	{
		flag=true;
		for(int i=0;i<_size;i++)
		{
		    if(elem[i]!=vec.elem[i]) 
		    {
		    	flag=false;
		    	break;
		    }
		}
	}
	return flag;
}
istream& operator>>(istream& is, MyVector & vec)
{
	
	is>>vec._size; 
	for(int i=0;i<vec._size;i++)
	{
		is>>vec.elem[i];
	}
	return is;
} 


              //first input n as a _size, then input elem[0],elem[1],бн,elem[n-1];
ostream& operator<<(ostream& os, const MyVector & vec)
{
	int size=vec.size();
	os<<vec.elem[0];
	for(int i=1;i<size;i++)
	{
		os<<" "<<vec.elem[i];
	}
	
	return os;
}
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
       {//vec=vec;
              cout << vec << endl;
              MyVector vec2 = vec;
              Elements sum = getSum(vec);
              int average = (int)sum / vec.size();
              for(int i=0;i<vec.size();i++)
              {
                     if( vec[i] < average )
                     {
                            vec [i] = average;
                     }
              }
              cout << vec << endl;
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

