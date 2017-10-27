#include <bits/stdc++.h>

using namespace std;

int main()
{
	int num[9]={1,2,3,4,5,6,7,8,9};
	int n;
	scanf("%d",&n);
	if(n<=0)
		printf("\n");
	else
		do
		{
			printf("%d",num[0]);
			for(int i=1;i<n;i++)
				printf(" %d", num[i]);
			printf("\n");
		}while(next_permutation(num,num+n));
	return 0;
}