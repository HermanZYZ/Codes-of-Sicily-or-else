#include<iostream>
#include<string>
#include<stdio.h>
#include<algorithm>
using namespace std;
int a[1000001];
int main()
{
	int n, m;
	while (cin>>n>>m)
	{
		for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
		sort(a, a + n);
		for (int i = n - 1; i >= n - m; i--)
		{
			if (i != n - 1)
				printf(" ");
			printf("%d", a[i]);
		}
		printf("\n");
	}
}
