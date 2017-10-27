#include<iostream>
#include<cmath>
class MyPoint
{
private:
    double x, y;
public:
    // The no-arg constructor that contruccts a point with coordinates(0,0)
    MyPoint(){
    	x=0,y=0; 
	} 
    MyPoint(double x, double y){
    	this-> x=x;
    	this-> y=y;
    }
    double getX() const{
    	return x;
	}
    double getY() const{
    	return y;
	}
    //display the distance between two points in two-dimensional space.
    double distance(const MyPoint &point){
    	double tmpx=pow(point.x-x,2);
    	double tmpy=pow(point.y-y,2);
    	return sqrt(tmpx+tmpy);
    }
};
class ThreeDPoint : public MyPoint
{
private:
    double z;
public:
    // The no-arg constructor that contruccts a point with coordinates(0,0,0) 
    ThreeDPoint():MyPoint(0,0){
    	z=0;
    }
    ThreeDPoint(double x, double y, double z):MyPoint(x,y){
    	this -> z=z;
    }
    double getZ() const{
    	return z;
	}
    //display the distance between two points in Three-dimensional space.
    double distance(const ThreeDPoint &point){
    	double tmpx=pow(getX()-point.getX(),2);
    	double tmpy=pow(getY()-point.getY(),2);
    	double tmpz=pow(z-point.z,2);
    	return sqrt(tmpx+tmpy+tmpz);
    }
};
