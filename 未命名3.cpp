#include<iostream>

using namespace std;
int hanoi(int n) {
	if(n<1) return 0;
	hanoi(n-1);
	hanoi(n-1);
}
int main()
{
	int n;
	cin>>n;
	cout<<hanoi;
}
