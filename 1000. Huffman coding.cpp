#include<iostream>
#include<queue>

using namespace std;

int main()
{
	int ans=0;
	priority_queue <int,vector <int>,greater <int> > que;
	int n,num;
	char temp;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>temp>>num;
		que.push(num);
	}
	while(que.size()>1)
	{
		int a=que.top();
		que.pop();
		int b=que.top();
		que.pop();
		
		ans = ans + a + b;
		que.push(a+b); 
	}
	cout<<ans<<endl;
	return 0;
} 
