// Problem#: 1934
// Submission#: 4821203
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include<stdio.h>

#define MAX 500001

int left[MAX]={0};
int right[MAX]={0};

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        
        for(int i=1;i<=n;i++)
        {
            left[i]=i-1;
            right[i]=i+1;
        }
        
        int c,a,b,temp;
        while(m--)
        {
            scanf("%d%d%d",&c,&a,&b);
            if(c==1)
            {
                temp=left[a];
                left[a]=left[b];
                right[left[a]]=a;
                right[temp]=right[a];
                left[right[a]]=temp;
                right[a]=b;
                left[b]=a;
            }
            else 
            {
                temp=left[a];
                left[a]=b;
                right[temp]=right[a];
                left[right[a]]=temp;
                right[a]=right[b];
                right[b]=a;
                left[right[a]]=a;
            }
        }
        int index=0;
        for(int i=1;i<=n;i++)
        {
            if(left[i]==0)
            {
                index=i;
                break;
            }
        }
        printf("%d ",index);
        while(index=right[index])
        {
            if(index==n+1)
                break;
            else
            {
                printf("%d ",index);
            }
        }
        printf("\n");
    }
}                                 
