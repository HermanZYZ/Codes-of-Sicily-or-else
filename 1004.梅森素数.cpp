//2、3、5、7、13、17、19、31 
#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	 int p,a[8]={2,3,5,7,13,17,19,31};
	 while(cin>>p)
	 {
	 	bool flag=true;
	 	for(int i=0;i<8;i++)
	 	{
	 		if(p==a[i])
	 		{
	 			cout<<"Yes"<<endl;
	 			flag=false;
	 			break;
	 		}
	 	}
	 	if(flag)
	 		cout<<"No"<<endl;
	 } 
	 return 0;
}
