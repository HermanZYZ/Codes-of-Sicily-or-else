#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int arr[3005];
int arr1[3005];
int main()
{
	int n,N;
	while(cin >> n)
    {
    	int i=0,e=0;
    	N = n;
    	while(n--)
    	{
    		cin >> arr[i];
    		i++;
		}
		n = N;
		if(n>=3)
		{
		for(i=0;i<n-1;i++)
		{
			arr1[i] = abs(arr[i]-arr[i+1]);
			
		}
		sort(arr1,arr1+n-1);
		for(i=0;i<n-2;i++)
		{
			if(arr1[0]==n-1)
			{
			    if(arr1[i]-arr1[i+1]==1) e+=1;
			}
			else if(arr1[0]==1)
			{
				if(arr1[i]-arr1[i+1]==-1) e+=1;
			} 
		}
		if(e==n-2) 
		   cout << "Jolly" << endl;
		else 
		   cout << "Not jolly" <<endl;
	    } 
	    
	    if(n==1) 
		   cout << "Jolly" << endl;
	    if(n==2) 
	    {
	    	if(abs(arr[0]-arr[1])==1) 
			   cout << "Jolly" << endl;
	    	else 
			   cout << "Not jolly" << endl;
		}
	}
	
	return 0;
}

