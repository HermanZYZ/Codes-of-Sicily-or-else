#include<iostream>
#include<cstdio>
using namespace std;
int arr1[30],arr2[30];
int main()
{
	arr1[1]=31;
    arr1[2]=28;
arr1[3]=31;
arr1[4]=30;
arr1[5]=31;
arr1[6]=30;
arr1[7]=31;
arr1[8]=31;
arr1[9]=30;
arr1[10]=31;
arr1[11]=30;
arr1[12]=31;
arr2[1]=31;
arr2[2]=29;
arr2[3]=31;
arr2[4]=30;
arr2[5]=31;
arr2[6]=30;
arr2[7]=31;
arr2[8]=31;
arr2[9]=30;
arr2[10]=31;
arr2[11]=30;
arr2[12]=31;
	int year,mon,day;
	int i=1,date=0;
	while(scanf("%d/%d/%d",&year,&mon,&day) !=EOF)
	{
		if (( year % 4 == 0 && year % 100 != 0 ) || (year % 400 == 0))
		{
			do
			{
				date+=arr2[i-1];
				i++;
			}while(i<=mon);
			date=date+day;
			printf("%d\n",date);
		}
		else
		{
				do
			{
				date+=arr1[i-1];
				i++;
			}while(i<=mon);
			date=date+day;
			printf("%d\n",date);
		}
		date=0;
		i=1;
	}
	return 0;
}
