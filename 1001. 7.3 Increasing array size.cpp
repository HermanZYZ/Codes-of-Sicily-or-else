#include<iostream>

using namespace std;
int * doubleCapacity(int *list, int size)
{
	int dousize=2*size;
	int* arr= new int[dousize];
	for(int i=0;i<dousize;i++)
	{
		if(i<size)
			arr[i]=list[i];
		else
			arr[i]=0;
	}
	return arr;
} 
int main()
{
	int list[5]={1,2,3,4,5};
 	int *newlist = doubleCapacity(list,5);
 	for(int i=0;i<2*5;i++)
   		cout << *(newlist+i) << " ";
}
