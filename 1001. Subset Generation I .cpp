#include<bits/stdc++.h>

using namespace std;
#define MAX 10
string a="ABCDEFGHIJKLMNOPQRSTUV";
string b;
int n;
void dfs(int i)
{
	if(i==n)
		return;
	for(int j=i;j<n;j++)
	{
		b+=a[j];
		cout<<b<<'\n';
		dfs(j+1);
		b=b.substr(0,b.length()-1);
	}
}

int main()
{
    cin>>n;
    cout<<endl;
    dfs(0);
    return 0;
}
