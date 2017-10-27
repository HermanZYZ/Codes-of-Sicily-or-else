#include<iostream>
#include<string>
#include<cstdio> 
using namespace std;

void mon(int n)
{
	switch(n)
	{
		case 1:  printf("January"); break; 
		case 2:  printf("February"); break; 
		case 3:  printf("March"); break; 
		case 4:  printf("April"); break; 
		case 5:  printf("May"); break; 
		case 6:  printf("June"); break; 
		case 7:  printf("July"); break; 
		case 8:  printf("August"); break; 
		case 9:  printf("September"); break; 
		case 10: printf("October"); break; 
		case 11: printf("November"); break; 
		case 12: printf("December"); break; 
	}
	return ; 
}

void week(int n)
{
	switch(n)
	{
		case 1: printf("Monday"); break; 
		case 2: printf("Tuesday"); break; 
		case 3: printf("Wednesday"); break; 
		case 4: printf("Thursday"); break; 
		case 5: printf("Friday"); break; 
		case 6: printf("Saturday"); break; 
		case 0: printf("Sunday"); break; 
	}
	return ; 
}
int main()
{
	int arr[]={0,31,28,31,30,31,30,31,31,30,31,30,31,0,0};
	int year,day;
	cin>>year>>day;
	if(year%400==0 || (year%4==0 && year%100!=0))
		arr[2]=29;
	else
		arr[2]=28;
	int sum=day;
	for(int i=1;i<13;i++)
	{
		mon(i); 
		cout<<" 1, "<<year<<" is ";
		week(sum); 
		sum+=arr[i];
		sum%=7;
		cout<<endl;
	}
	return 0;
}
