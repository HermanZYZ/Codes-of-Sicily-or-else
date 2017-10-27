#include <iostream>
 #include <math.h>

 using namespace std;

 bool solve(const int &a, const int &b, const int &j)
 {
     if (a == floor((double)(j * (sqrt(5.0)+1))/2.0) && a + j == b)
         return true;
     else
         return false;
 }

 int main()
 {
     int a, b;

     while (cin >> a >> b){
         if (a > b)
             swap(a, b);
         int j = floor((double)(a * (sqrt(5.0)-1))/2.0);
         
         if (solve(a, b, j) || solve(a, b, j+1))
             cout << "0\n";
         else
             cout << "1\n";
     }
     return 0;
 } 
