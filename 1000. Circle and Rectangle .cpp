#include<iostream>
using namespace std;
 

class Point
{
private:
	double x,y;
public:
	Point();
	Point(double xv,double yv);
	Point(Point& pt);
	double getx();
	double gety();
};

Point::Point()
{
	x=y=0;
}

Point::Point(double xv,double yv){
	x=xv;
	y=yv;
}

Point::Point(Point& pt){
	x=pt.x;
	y=pt.y;
}

double Point::getx(){
	return x;
}

double Point::gety(){
	return y;
}

class Circle : public Point
{
	double r;
public:
	Circle();
	Circle(double xv,double yv,double rv=0);
	Circle(Circle& ci);
	double getr();
	int position(Point &pt);
} ;

Circle::Circle():Point(){
	r=0;
}

Circle::Circle(double xv,double yv,double rv):Point(xv,yv){
	r=rv;
}

Circle::Circle(Circle& ci):Point(ci.getx(),ci.gety()){
	r=ci.r;
}

double Circle::getr(){
	return r;
}

int Circle::position(Point& pt){
	double temp=(pt.getx()-getx())*(pt.getx()-getx())
				+(pt.gety()-gety())*(pt.gety()-gety());
	if(r*r<temp) return 1;
	if(r*r==temp) return 0;
	else return -1;
}

class Rectangle : public Point
{
	double length,width;
public:
	Rectangle();
	Rectangle(double xv,double yv,double length=0,double width=0);
	Rectangle(Rectangle& re);
	double getLength();
	double getWidth();
	int position(Point &pt);
};

Rectangle::Rectangle():Point(){
	length=width=0;
}

Rectangle::Rectangle(Rectangle& re)
	:Point(re.getx(),re.gety()){
	length=re.length;
	width=re.width;
}

Rectangle::Rectangle(double xv,double yv,double len,double wid)
	:Point(xv,yv){
	length=len;
	width=wid;	
}

double Rectangle::getLength(){
	return length;
}

double Rectangle::getWidth(){
	return width;
}

int Rectangle::position(Point& pt){
	if(pt.getx()>getx() && pt.getx()<getx()+length){
		if(pt.gety()>gety() && pt.gety()<gety()+width) return -1;
		else if(pt.gety()==gety() || pt.gety()==gety()+width) 
			return 0;
		else return 1;
	}
	else if(pt.getx()==getx() || pt.getx()==getx()+length){
		if(pt.gety()>=gety() && pt.gety()<=gety()+width) return 0;
		else return 1;
	}
	else return 1;
}

int main()
{
	Circle cc1(1,2,3);
	Rectangle rt1(1,2,3,4);
	Point p1(10,10);
	cout<<"point p1:";
	switch(rt1.position(p1))
	{
	  case 0:cout<<"on-rectangle"<<endl;break;
	  case -1:cout<<"inside-rectangle"<<endl;break;
	  case 1:cout<<"outside-rectangle"<<endl;break;
	}
	switch(cc1.position(p1))
	{
	  case 0:cout<<"on-circle"<<endl;break;
	  case -1:cout<<"inside-circle"<<endl;break;
	  case 1:cout<<"outside-circle"<<endl;break;
	}
	return 0;
}
