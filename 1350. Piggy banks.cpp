#include<stdio.h>
#include<string.h>

#define MAX 1000005

int visited[MAX]={0};
int bank[MAX]={0};

int main()
{
	int n,num;
	while(scanf("%d",&n) != EOF)
	{
		int count=0;
		num=0;
		memset(visited,0,sizeof(visited));
		for(int i=1;i<=n;i++)
			scanf("%d",&bank[i]);
		for(int i=1;i<=n;i++)
		{
			count++;
			int temp=i;
			while(1)
			{
				if(visited[temp])
				{
					if(visited[temp]==count)
						num++;
					break;
				}
				else
				{
					visited[temp]=count;
					temp=bank[temp];
				}
			}
		}
		printf("%d\n",num);
	}
} 
