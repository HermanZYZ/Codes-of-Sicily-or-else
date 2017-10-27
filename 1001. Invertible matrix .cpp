#include<iostream>
#include<string>
#include<cstdio> 
#include<iomanip>
#include<cstring>

using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		double arr[3][3];
		for(int i=0;i<2;i++)
			for(int j=0;j<2;j++)
				cin>>arr[i][j];
	//	cout<<arr[0][0]*arr[1][1]<<endl;
		double det=arr[0][0]*arr[1][1]-arr[0][1]*arr[1][0];
	//	cout<<det<<endl;
		if(!det)
			cout<<"Not Invertible"<<endl;
		else
		{
			arr[0][0]/=det,arr[1][1]/=det;
			swap(arr[0][0],arr[1][1]);
			arr[0][1]=-arr[0][1]/det;
			arr[1][0]=-arr[1][0]/det;
			cout<<fixed<<setprecision(3)<<arr[0][0]<<" "<<arr[0][1]<<endl
				<<arr[1][0]<<" "<<arr[1][1]<<endl;
		}
		cout<<endl;
	}
}
