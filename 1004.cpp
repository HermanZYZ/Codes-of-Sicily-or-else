#include<iostream>
using namespace std;
int main()
{
	int a;
	cin>>a;
	if(a%5==0 && a%6==0)
	cout<<"Is "<<a<<" divisible by 5 and 6? true"<<endl;
	else
	cout<<"Is "<<a<<" divisible by 5 and 6? false"<<endl;
	if(a%5==0 || a%6==0)
	cout<<"Is "<<a<<" divisible by 5 or 6? true"<<endl;
	else
	cout<<"Is "<<a<<" divisible by 5 or 6? false"<<endl;
	if((a%5==0 && a%6!=0) || (a%6==0 && a%5!=0))
	cout<<"Is "<<a<<" divisible by 5 or 6, but not both? true"<<endl;
	else
	cout<<"Is "<<a<<" divisible by 5 or 6, but not both? false"<<endl;
	return 0;
} 
