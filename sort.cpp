#include<iostream>
#include<algorithm>
using namespace std;
bool c(int a,int b)
{
	return a<b;	
}
int main()
{
	int arr[205],num;
	cin>>num;
	for(int i=0;i<num;i++)
		cin>>arr[i];
	sort(arr,arr+num,c);
	for(int i=0;i<num;i++)
		cout<<arr[i]<<endl;
	return 0;
} 
