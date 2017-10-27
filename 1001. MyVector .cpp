#include<iostream>
#include<cstdio>
using namespace std;

class MyVector 

{

public: 

         MyVector(int = 0, int = 0, int = 0);

         MyVector(const MyVector &);

         void display();

         friend MyVector add(MyVector &v1, MyVector &v2);

         friend MyVector sub(MyVector &v1, MyVector &v2);

         friend int dot(MyVector &v1, MyVector &v2);

         friend MyVector cross(MyVector &v1, MyVector &v2);

private:

         int x, y, z;

};

MyVector::MyVector(int x,int y,int z)
{
	this -> x=x;
	this -> y=y;
	this -> z=z;
}
	
MyVector::MyVector(const MyVector & anotherVector)
{
	x=anotherVector.x;
	y=anotherVector.y;
	z=anotherVector.z;
}
	
void MyVector::display()
{
	printf("(%d,%d,%d)\n",x,y,z);
	return ;
}

MyVector add(MyVector &v1, MyVector &v2)
{
	MyVector vector;
	vector.x=v1.x+v2.x;
	vector.y=v1.y+v2.y;
	vector.z=v1.z+v2.z;
	return vector;
}

MyVector sub(MyVector &v1, MyVector &v2)
{
	MyVector vector;
	vector.x=v1.x - v2.x;
	vector.y=v1.y - v2.y;
	vector.z=v1.z - v2.z;
	return vector;
}

int dot(MyVector &v1, MyVector &v2)
{
	return v1.x*v2.x + v1.y*v2.y + v1.z*v2.z;
}

MyVector cross(MyVector &v1, MyVector &v2)
{
	MyVector vector;
	vector.x = v1.y*v2.z - v1.z*v2.y;
	vector.y = v1.z*v2.x - v1.x*v2.z;
	vector.z = v1.x*v2.y - v1.y*v2.x;
	return vector;
}

int main()

{

         MyVector a;

         MyVector b(1);

         MyVector c(2,3);

         MyVector d(3,4,5);

         MyVector e(c);

 

         MyVector x = add(a, b);

         x.display();

         MyVector y = sub(b, c);

         y.display();

         MyVector z = cross(c, d);

         z.display();

         int w = dot(d, e);

         cout << w << endl;


 

         return 0;

}

