#include<iostream>
#include<string>
#include<cstdio> 
#include<iomanip>
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
int main()
{
	int arr[]={0,31,28,31,30,31,30,31,31,30,31,30,31,0,0};
	int year,day,month;
	cin>>year>>day>>month;
	if(year%400==0 || (year%4==0 && year%100!=0))
		arr[2]=29;
	else
		arr[2]=28;
	int sum=day;
	mon(month);
	cout<<" "<<year<<endl; 
	cout<<"     Sun     Mon     Tue     Wed     Thu     Fri     Sat"<<endl; 
	for(int i=1;i<month;i++)
		sum+=arr[i];
	sum%=7;
	for(int i=0;i<sum;i++)
		cout<<setw(8)<<right<<" ";
	for(int i=1;i<=arr[month];i++)
	{
		if(i==arr[month] && (sum+i-1)%7==6) 
			cout<<setw(8)<<right<<i;
		else if((sum+i-1)%7==6)
			cout<<setw(8)<<right<<i<<endl;
		else
			cout<<setw(8)<<right<<i;
	}
	cout<<endl;
	return 0;
}
