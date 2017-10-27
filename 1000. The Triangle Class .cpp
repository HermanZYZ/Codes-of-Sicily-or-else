#include<iostream>

using namespace std;

#include<cmath>

class GeometricObject
{
public:
    GeomtricObject() 
    {
        color = "white";
        filled = false;
    }
    GeometricObject(string color, bool filled)
    {
        this->color = color;
        this->filled = filled;
    }
    string getColor()
    { return color; }
    void setColor(string color)
    { this->color = color; }
    bool isFilled()
    { return filled; }
    void setFilled(bool filled)
    { this->filled = filled;}
    string toString()
    {
        return "Geometric object color "+color +
            " filled " + ((filled) ? "true" : "false");
    }
private:
    string color;
    bool filled;
};
#include<cmath>
class Triangle:public GeometricObject
{
	double side1,side2,side3;
public:
	Triangle(){
		side1=side2=side3=1.0;
	}	
	Triangle(double s1,double s2,double s3){
		if(s1<(s2+s3) && s2<(s1+s3) && s3<(s1+s2)){
			side1=s1;
			side2=s2;
			side3=s3;
		}
		else{
			cout<<"illegal sides!"<<endl;
			side1=side2=side3=1.0;
		}
	}
	
	double getside1(){
		return side1;}
	void setside1(double s1){
		side1=s1;
	}
	double getside2(){
		return side2;}
	void setside2(double s2){
		side2=s2;
	}
	double getside3(){
		return side3;}
	void setside3(double s3){
		side3=s3;
	}
	double getArea(){
		double p=getPerimeter()/2;
		return sqrt(p*(p-side1)*(p-side2)*(p-side3));
	}
	double getPerimeter(){
		return side1+side2+side3;
	}
};

