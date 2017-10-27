#include <iostream>
#include <queue>
#include <vector>
#include <string.h>
#include <stdio.h>
#include <set>

#define MAX 100001

using namespace std; 

vector <int> adjacent[MAX];//аз╫с╠М

int inDegree[MAX];
set<int> result;

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        memset(inDegree,0,sizeof(inDegree));
        memset(adjacent,0,sizeof(adjacent));
        int n,m;
        scanf("%d%d",&n,&m);
        int a,b;
        while(m--){
            scanf("%d%d",&a,&b);
            adjacent[a].push_back(b);
            inDegree[b]++;
        }
        for(int i=1;i<=n;++i){
            if(inDegree[i] == 0){
                result.insert(i);
            }
        }
        
        while(!result.empty()){
            int temp = *result.begin();

	        printf("%d ",temp);
			result.erase(result.begin());
            
            for(int i=0;i<adjacent[temp].size();++i){
                inDegree[adjacent[temp][i]]--;
                if(inDegree[adjacent[temp][i]] == 0){
                    result.insert(adjacent[temp][i]);
                }
            }
        }
        cout<<endl;
    }
    
}                                 
