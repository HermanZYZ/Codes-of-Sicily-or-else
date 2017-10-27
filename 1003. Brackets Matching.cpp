#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	stack<char> s1,s2,s3;
	while(cin>>n)
	{
		char bracket;
		bool flag = true;
		while(!s1.empty())
			s1.pop();
		while(!s2.empty())
			s2.pop();
		while(!s3.empty())
			s3.pop();
		for(int i=0;i<n;i++)
		{
			cin>>bracket;
			if(bracket=='(')
				s1.push(bracket);
			else if(bracket=='[')
				s2.push(bracket);
			else if(bracket=='{')
				s3.push(bracket);
			else if(bracket==')' && !s1.empty())
				s1.pop();
			else if(bracket==']' && !s2.empty())
				s2.pop();
			else if(bracket=='}' && !s3.empty())
				s3.pop();
			else
				flag=false;
		}
		if(!flag || !s1.empty() || !s2.empty() || !s3.empty())
			cout<<"NO"<<endl;
		else
			cout<<"YES"<<endl;
	}

	return 0;
}