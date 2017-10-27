#include <cstdio>
#include <iostream>
#include <iomanip>
using namespace std;
class Rectangle
{
    private:
        double width,height;
    public:
        Rectangle()// ��ʼ�� 
        {
            width=0;
            height=0;
        }
        Rectangle(double w,double h)//��һ�ִ������ݷ�ʽ 
        {
            width=w;
            height=h;
        }
        double getWidth()//�ڶ��� �������ݷ�ʽ 
        {
            return width;
        }
        double getHeight()//�ڶ��� �������ݷ�ʽ 
        {
            return height;
        }
        void setWidth(double x)//�ڶ��� �������ݷ�ʽ 
        {
            width=x;
        }
        void setHeight(double y)//�ڶ��� �������ݷ�ʽ 
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
