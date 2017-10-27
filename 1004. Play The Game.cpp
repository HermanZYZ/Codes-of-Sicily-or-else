#include <cstdio>
#include <cstring>
#include <iostream>
#define inf 0x3f3f3f3f
using namespace std;
const int N=100;
int match[N];
int lx[N],ly[N];
int sx[N],sy[N];
int weight[N][N];
int n;
int dfs(int x){
    sx[x]=true;
    for(int i=0;i<n;i++){
        if(!sy[i]&&lx[x]+ly[i]==weight[x][i]){
            sy[i]=true;
            if(match[i]==-1||dfs(match[i])){
                match[i]=x;
                return true;
            }
        }
    }
    return false;
}
int fax(int x){
    if(!x){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                weight[i][j]=-weight[i][j];
            }
        }
    }
    memset(match,-1,sizeof(match));
    for(int i=0;i<n;i++){
        ly[i]=0;
        lx[i]=-inf;
        for(int j=0;j<n;j++){
            if(weight[i][j]>lx[i]){
                lx[i]=weight[i][j];
            }
        }
    }
    for(int i=0;i<n;i++){
        while(1){
            memset(sx,0,sizeof(sx));
            memset(sy,0,sizeof(sy));
            if(dfs(i))
                break;
            int mic=inf;
            for(int j=0;j<n;j++){
                if(sx[j]){
                    for(int k=0;k<n;k++){
                        if(!sy[k]&&lx[j]+ly[k]-weight[j][k]<mic){
                            mic=lx[j]+ly[k]-weight[j][k];
                        }
                    }
                }
            }
            if(mic==0)
                return -1;
            for(int j=0;j<n;j++){
                if(sx[j]){
                    lx[j]-=mic;
                }
                if(sy[j]){
                    ly[j]+=mic;
                }
            }
        }
    }
    int sum=0;
    for(int i=0;i<n;i++){
        if(match[i]>=0){
            sum+=weight[match[i]][i];
        }
    }
    if(!x){
        sum=-sum;
    }
    return sum;
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--)
    {
    	scanf("%d",&n);
	    for(int i=0;i<n;i++){
	        for(int j=0;j<n;j++){
	            scanf("%d",&weight[i][j]);
	        }
	    }
	    int h=fax(1);
	    cout<<h<<endl;
    }
    return 0;
}
/*
5
3 4 6 4 9
6 4 5 3 8
7 5 3 4 2
6 3 2 2 5
8 4 5 4 7
*/
