//����n����n<100��������100�������������mС������m<100�� 

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
		arr[tmp]++;//���������±���������������������ظ���arr[tmp]��¼�ظ����� 
	}
	int cnt=0;
	for(int i=0;i<n;i++)
	{
		if(arr[i])//�ж��������ǵ�arr[i] != 0(==0ʱ��Ϊfalse) 
			cnt+=1;
		if(cnt>=m)
		{
			cout<<i<<endl;
			break;
		}
	} 
	return 0;
}
