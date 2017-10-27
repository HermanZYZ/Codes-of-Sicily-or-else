// Problem#: 1031
// Submission#: 4980277
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include<iostream>
#include<cstring>
#include<queue>
#include<map>
#include<vector>
#include<string>
using namespace std;
#define INF 0x3f3f3f3f
#define MAXN 220
struct node{
    int x,y;
    int d;
    node(int str1,int str2,int dis){
        x = str1;
        y = str2;
        d = dis;
    }
};

int S,T,dis[MAXN],n;
vector<node>way[MAXN];
map<string,int>mymap;
typedef pair<int,int>pii;

void init(){
    int num = 1,d;
    string str1,str2;
    mymap.clear();
    memset(way,0,sizeof(way));
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>str1>>str2>>d;
        if(!mymap.count(str1))
            mymap.insert(make_pair(str1,num++));
        if(!mymap.count(str2))
            mymap.insert(make_pair(str2,num++));
        way[mymap[str1]].push_back(node(mymap[str1],mymap[str2],d));
        way[mymap[str2]].push_back(node(mymap[str2],mymap[str1],d));
    }
}

int dijkstra(){
    priority_queue<pii>q;
    memset(dis,INF,sizeof(dis));
    dis[S] = 0;
    pii cur;
    q.push(make_pair(0,S));
    while(!q.empty()){
        cur = q.top();
        q.pop();
        int x = cur.second;
        if(cur.first != dis[x]) continue;
        for(int i=0;i<way[x].size();++i){
            int y = way[x][i].y;
            int w = way[x][i].d;
            if(dis[x] + w < dis[y]){
                dis[y] = dis[x] + w;
                q.push(make_pair(dis[y],y));
            }
        }
    }
    if(dis[T] == INF)
        return -1;
    else return dis[T];
}

int main(){
    int k;
    cin>>k;
    while(k--){
        init();
        string str1,str2;
        cin>>str1>>str2;
        if(str1==str2){
            cout<<0<<endl;
            continue;
        }
        if(!mymap[str1]||!mymap[str2]){
            cout<<-1<<endl;
            continue;
        }
        S = mymap[str1];
        T = mymap[str2];
        int ans = dijkstra();
        cout<<ans<<endl;
    }
    return 0;
}                                 
