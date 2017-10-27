#include<string>
#include<iostream>

using namespace std;
class Human {
 public:
     virtual string getSkinColor() = 0;
 };
 
 class European :public Human
 {
 	string skinColor;
public:
 	European()
 	{
 		skinColor="white";
 	}
 	string getSkinColor()
 	{
 		return skinColor;
 	}
 };
 class African :public Human
 {
 	string skinColor;
public:
	African()
	{
		skinColor="black";
	}
 	string getSkinColor()
 	{
 		return skinColor;
 	}
 };
