//输入n个（n<100）不大于100的正数，输出第m小的数（m<100） 

#include<iostream>
using namespace std;

int main()
{
	int arr[105]={0,};
	int n,m;
	cin>>n>>m;
	int tmp;
	for(int i=0;i<n;i++)
	{
		cin>>tmp;
		arr[tmp]++;//利用数组下标来进行排序，若输入的数重复，arr[tmp]记录重复次数 
	}
	int cnt=0;
	for(int i=0;i<n;i++)
	{
		if(arr[i])//判断条件就是当arr[i] != 0(==0时即为false) 
			cnt+=1;
		if(cnt>=m)
		{
			cout<<i<<endl;
			break;
		}
	} 
	return 0;
}
