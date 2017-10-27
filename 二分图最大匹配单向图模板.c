#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int e[500][500];
int match[500];
int book[500];
int n,m;

int dfs(int u)
{
    int i;
    for(i=1;i<=m;i++)
    {
        if(book[i]==0&&e[u][i]==1)
        {
            book[i]=1; //标记点i已访问过
            if(match[i]==0||dfs(match[i]))
            {
                //更新配对关系
                match[i]=u;//注意不是match[u]=i;

                return 1;
            }
        }
    }
         return 0;
    }
int main()
{
   //freopen("in.txt","r",stdin);
   int i,j,t1,t2,sum=0;
   int k,a;
   while(scanf("%d%d",&n,&m)!=EOF){
     memset(e,0,sizeof(e));
     memset(book,0,sizeof(book));
     sum=0;
   for(i=1;i<=n;i++){
    scanf("%d",&k);
    for(j=1;j<=k;j++)
    {
        scanf("%d",&a);
    e[i][a]=1;

   }
   }
   for(i=1;i<=n;i++)
    match[i]=0;

   for(i=1;i<=n;i++){
    
    memset(book,0,sizeof(book)); //清空上次搜索时的标记
    if(dfs(i))
        sum++;     //寻找增广路，如果找到，配对数加1.
   }
   printf("%d\n",sum);
   }
    return 0;
}
