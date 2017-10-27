#include <bits/stdc++.h>  
  
using namespace std ;  
  
int a[3000005] , b[3000005] ;   
int visit[1000005] ;   
int main ()   
{  
    int c , n , k ;   
    while(scanf("%d %d" , &c , &n) != EOF)  
    {  
        for(int i=0 ; i<n ; i++)  
            scanf("%d" , &a[i]) ;  
        k = 0 ;   
        for(int i=n-1 ; i>=0 ; i--)  
        {  
            if(!visit[a[i]])  
            {  
                b[k++] = a[i] ;  
                visit[a[i]] = 1 ;   
            }                 
        }  
        printf("%d\n" , k) ;  
        printf("%d" , b[k-1]) ;    
        for(int i = k-2 ; i >= 0 ; i--)  
            printf(" %d" , b[i]) ;   
        printf("\n") ;  
        memset(visit , 0 , sizeof(visit)) ;    
    }  
    return 0 ;  
} 


//Time Limited Execced 10sco
//#include<iostream>
//#include<vector>
//#include<cstdio>
//#include<cstring>
//
//using namespace std;
//
//bool exist[1000005]={0};
//vector<int> result;
//
//int main()
//{
//	int c,n;
//	while(scanf("%d%d",&c,&n) != EOF)
//	{
//		memset(exist,false,sizeof(exist));
//		int elem;
//		for(int i=0;i<n;i++)
//		{
//			scanf("%d",&elem);
//			if(exist[elem])
//			{
//				exist[elem] = 0;
//				for(vector<int>::iterator it= result.begin();it != result.end();it++)
//				{
//					if((*it) == elem)
//					{
//						result.erase(it);
//						result.push_back(elem);
//						break;
//					}
//				}
//			}
//			else
//			{
//				result.push_back(elem);
//				exist[elem] = 1;
//			}
//		}
//		
//		printf("%d\n",result.size());
//		if(result.size()==0)
//		{
//			continue;
//		}
//		printf("%d",result[0]);
//		for(int i=1;i<result.size();i++)
//		{
//			printf(" %d",result[i]);
//		}
//		printf("\n");
//		result.clear();
//	}
//} 

