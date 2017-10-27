#include<iostream>

using namespace std;

template <typename T>
//int binary_search(T a, int n, int key )
int binarySearch(T array[], T key, int arraySize)
{
	int mid, front=0, back=arraySize-1;
	while (front<=back)
	{
		mid = (front+back)/2;
		if (array[mid]==key)
		return mid;
		if (array[mid]<key)
		front = mid+1;
		else back = mid-1;
	}
	return -1;
}

int main()
{
	char a[]={'b','d','f','g','j','o'};
	cout<<binarySearch(a,'j',6)<<endl;
	return 0;
}
