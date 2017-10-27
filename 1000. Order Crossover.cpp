#include <bits/stdc++.h>

using namespace std;

const int Max=105;
int parent1[Max],parent2[Max];
int child1[Max],child2[Max];
bool child_1[Max],child_2[Max];

int main()
{
	int n,start,end;
	while(~scanf("%d",&n))
	{
		memset(parent1,0,sizeof(parent1));
		memset(parent2,0,sizeof(parent2));
		memset(child1,0,sizeof(child1));
		memset(child2,0,sizeof(child2));
		memset(child_1,0,sizeof(child_1));
		memset(child_2,0,sizeof(child_2));
		for(int i=0;i<n;i++)
			scanf("%d",&parent1[i]);
		for(int i=0;i<n;i++)
			scanf("%d",&parent2[i]);

		scanf("%d%d",&start,&end);
		for(int i=start;i<=end;i++)
		{
			child_1[parent1[i]]=1;
			child_2[parent2[i]]=1;
			child1[i]=parent1[i];
			child2[i]=parent2[i];
		}

		for(int i=0,index=0;i<n;i++)
		{
			if(index==start)
			{
				index=end+1;
			}
			if(child_1[parent2[i]]==0)
			{
				child1[index]=parent2[i];
				index++;
			}
		}
		for(int i=0,index=0;i<n;i++)
		{

			if(index==start)
			{
				index=end+1;
			}
			if(child_2[parent1[i]]==0)
			{
				child2[index]=parent1[i];
				index++;
			}
		}

		printf("%d", child1[0]);
		for(int i=1;i<n;i++)
			printf(" %d", child1[i]);
		printf("\n");

		printf("%d", child2[0]);
		for(int i=1;i<n;i++)
			printf(" %d", child2[i]);
		printf("\n");
	}
}