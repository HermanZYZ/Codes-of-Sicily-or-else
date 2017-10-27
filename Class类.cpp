#include <cstdio>
#include <iostream>
#include <iomanip>
using namespace std;
class Rectangle
{
    private:
        double width,height;
    public:
        Rectangle()// 初始化 
        {
            width=0;
            height=0;
        }
        Rectangle(double w,double h)//第一种传入数据方式 
        {
            width=w;
            height=h;
        }
        double getWidth()//第二种 传入数据方式 
        {
            return width;
        }
        double getHeight()//第二种 传入数据方式 
        {
            return height;
        }
        void setWidth(double x)//第二种 传入数据方式 
        {
            width=x;
        }
        void setHeight(double y)//第二种 传入数据方式 
        {
            height=y;
        }
        double getArea()
        {
            return width*height;
        }
        double getPerimeter()
        {
            return 2.0*(width + height);
        }
};  
int main()
 {
     Rectangle r1;
     cout << fixed << setprecision(2);
     cout << "width: " << r1.getWidth() << "; Height: " << r1.getHeight() 
       << "; Area: " << r1.getArea() << "; perimeter: " << r1.getPerimeter() << endl;

     r1.setWidth(2.0);
     r1.setHeight(1.5);
     
     cout << "width: " << r1.getWidth() << "; Height: " << r1.getHeight() 
       << "; Area: " << r1.getArea() << "; perimeter: " << r1.getPerimeter() << endl;
     
     Rectangle r2(1.5, 2.0);
     cout << "width: " << r2.getWidth() << "; Height: " << r2.getHeight() 
       << "; Area: " << r2.getArea() << "; perimeter: " << r2.getPerimeter() << endl;
       
     return 0;
 }                               
