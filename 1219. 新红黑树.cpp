#include<bits/stdc++.h>
using namespace std;
const int INF = 1<<30; 
const int MAXN = 25;  
  
struct Tree 
{  
    int child, color, weight;  //child表示next节点的序号 
    Tree * next;  
} * tree[MAXN];  
  
void init() //建图 
{
    int a, b, c, w, n;  
    cin >> n;
    for (int i = 0; i <= n; i++) 
    {  
        tree[i] = new Tree;   //初始化 
        tree[i]->next = NULL;  
    }  
    tree[0]->weight = 0;   //根权值为0 
    for (int i = 0; i < n; i++) 
    {  
        Tree * tmp;
        cin >> a >> b >> c >> w;
        tmp = tree[a]->next;  
        tree[a]->next = new Tree;  
        tree[a]->next->child = b;  
        tree[a]->next->color = c;  
        tree[a]->next->weight = w;  //树枝的权值保存在第二个端点 
        tree[a]->next->next = tmp;  
        tree[b]->weight = w;  
    }  
}

void solve(int turn, int & value) 
{  
    Tree * tmp, * tmp1, * tmp2;  
    int f = 0, r = 1, l[MAXN];  //l数组用来遍历每个端点 
    int max = -INF, min = INF;  
    l[0] = 0;  
    while (f < r) 
    {  
        //枚举每一种情况 
        tmp = tree[l[f++]];  
        while ((tmp1 = tmp->next) != NULL) 
        {  
            l[r++] = tmp1->child;  
            if (tmp1->color == turn)  
            {  
                tmp2 = tmp->next;  
                tmp->next = tmp1->next;  
                int ret = value + turn * tmp1->weight;  
                solve(-turn, ret);  //递归研究每一种情况的结果 
                if (ret > max) 
                    max = ret;  //更新max值 
                if (ret < min) 
                    min = ret;  //更新min值 
                tmp->next = tmp2;  
            }  
            tmp = tmp1;  
        }  
    }  
    if (max == -INF || min == INF)  //对于某子树，某人已经没有树枝砍的时候，由另外一人砍，直到砍完该子树全部树枝 
        while (r--) 
            value -= turn * tree[l[r]]->weight;  
    else  
    {
        if(turn > 0)
            value = max;
        else
            value = min;
    }
}  
  
int main() 
{  
    int a, b, c, w, n;  
    cin >> n;
    for (int i = 0; i <= n; i++) 
    {  
        tree[i] = new Tree;   //初始化 
        tree[i]->next = NULL;  
    }  
    tree[0]->weight = 0;   //根权值为0 
    for (int i = 0; i < n; i++) 
    {  
        Tree * tmp;
        cin >> a >> b >> c >> w;
        tmp = tree[a]->next;  
        tree[a]->next = new Tree;  
        tree[a]->next->child = b;  
        tree[a]->next->color = c;  
        tree[a]->next->weight = w;  //树枝的权值保存在第二个端点 
        tree[a]->next->next = tmp;  
        tree[b]->weight = w;  
    }  
    int D = 0;  
    solve(1, D);  
    cout << D << endl; 
}                                   
