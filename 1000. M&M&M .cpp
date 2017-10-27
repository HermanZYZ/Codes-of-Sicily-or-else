#include<iostream>

using namespace std;

template <typename T>
T maximumValue (const T array[], const int size)
{
	T temp=array[0];
	for(int i=1;i<size;i++)
	{
		if(temp<array[i])
			temp=array[i];
	}
	return temp;
}

template <typename T>
T minimumValue (const T array[], const int size)
{
	T temp=array[0];
	for(int i=1;i<size;i++)
	{
		if(temp>array[i])
			temp=array[i];
	}
	return temp;
}

template <typename T>
T medianValue (const T array[], const int size)
{
	int Tarray[size];
	for(int i=0;i<size;i++) Tarray[i]=array[i]; 
	int temp=(size-1)/2;
	return Tarray[temp];
}

int main()
{
	int i1[5] = {1, 5, 2, 4,3};
	cout<<medianValue(i1,5)<<endl;
	return 0;
} 
