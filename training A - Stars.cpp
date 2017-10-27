#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define n 32001
int c[n+5], total[n+5];
int Lowbit(int t)  
{
    return t&(t^(t-1)); 
}
int Sum(int x)   
{
    int sum = 0;
    while(x > 0)
    {
        sum += c[x];
        x -= Lowbit(x);
    }
    return sum;
}
void add(int li, int val) 
{
    while(li<=n)
    {
        c[li] += val;
        li += Lowbit(li);
    }
} 
int main()
{
    int i, j, x, y, num;
    scanf("%d", &num); 
    memset(c, 0, sizeof(c)); 
    memset(total, 0, sizeof(total)); 
    for(i=1; i<=num; i++)
    {
        scanf("%d%d", &x, &y);
        add(x+1, 1);
        total[Sum(x+1)-1]++;
    }
    for(i=0; i<num; i++)
        printf("%d\n", total[i]);
}
