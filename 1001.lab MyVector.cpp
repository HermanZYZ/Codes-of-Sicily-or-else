#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

class MyVector
{
	double *data;
	int size; 
public:
	MyVector() //is the default constructor setting data = NULL and size = 0.
	{
		data=NULL;
		size=0;
	}
	MyVector(int size)  //is a constructor initializing the vector with the length of size and setting all elements zero.
	{
		this -> size=size;
		data= new double [size];
		memset(data,0,sizeof(data)); 
	}
	void create(int size) //creates a vector with the length of size and sets all elements zero. Note that if the vector is already created, delete it first.
	{
		if(data != NULL)
			delete data;
		data =new double [size];
		memset(data,0,sizeof(data));
	}
	void setValue(double value, int index) //sets the values[index] = value if 0<=index<size.
	{
		if(0<=index<size)
			data[index]=value;
	}
	void multiply(double k) //multiplies the vector by k.
	{
		for(int i=0;i<size;i++)
			data[i]*=k;
	}
	void display() //prints the vector like (1.0,2.4,3.5).
	{
		printf("(%g",data[0]);
		for(int i=1;i<size;i++)
		{
			printf(",%g",data[i]);
		}
		printf(")\n");
	}
	~MyVector() //is the destructor releasing the memory.
	{
		delete data;
	}
};

int main()

{

     int size,i;

     double input;

     double k;

     while (cin>>size>>k) {

            MyVector vector1(size);

            vector1.create(size); // this sentence is redundant

            for(i=0;i<size;i++){

                   cin>>input;

                   vector1.setValue(input,i);

            }

            vector1.display();

            vector1.multiply(k);

            vector1.display();

     }

     return 0;
}

