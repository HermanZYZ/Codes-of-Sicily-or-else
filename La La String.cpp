#include<iostream>
#include<set>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;

int countnum[255];
char s[50005];

int main()
{
	int t,Case=0;
	scanf("%d\n",&t);
	set<char> myset;
	while(t--)
	{
		memset(countnum,0,sizeof(countnum));
		myset.clear();
		Case++;
		int m;
		scanf("%d\n",&m);
		char temp;
		for(int i=0;i<m;i++)
		{
			scanf("%c\n",&temp);
			myset.insert(temp);
		}
		int k=0;
		while(scanf("%c",&s[k]) && s[k]!='\n')
		{
			k++;
		}
		string sub,resub;
		int num=0;
		
		
		for(int i=0;i<k;i++)
		{
			if(myset.find(s[i])==myset.end())
			{
				sub.clear();
				continue;
			}
			sub.clear(); 
			
			for(int j=i;j<k;j++)
			{
				if(myset.find(s[j])==myset.end())
				{
					sub.clear();
					break;
				}
				else if(countnum[s[j]]>=2)
				{
					sub.clear();
					break;
				}
				countnum[s[j]]++;
				sub+=s[j];
				resub=sub;
				reverse(resub.begin(),resub.end());
				if(sub==resub)
					num++;
				resub.clear();
			}
			memset(countnum,0,sizeof(countnum));
		}
		printf("Case #%d: %d\n",Case,num);
	}
	return 0;
}
