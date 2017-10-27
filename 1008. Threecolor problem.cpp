#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin>>n;
	multiset<int> Set;
	while(n--)
	{
		Set.clear();
		int len,index;
		string str;
		cin>>len>>index;
		cin>>str;
		for(int i=0;i<len;i++)
		{
			switch(str[i])
			{
				case 'r':Set.insert(1);break;
				case 'y':Set.insert(2);break;
				case 'b':Set.insert(3);break;
			}
		}
		int temp;
		multiset<int>::iterator it=Set.begin();
		for(int i=1;i<index;it++,i++);
		temp=*it;
		switch(temp)
		{
			case 1:cout<<"r"<<endl;break;
			case 2:cout<<"y"<<endl;break;
			case 3:cout<<"b"<<endl;break;
		}
	}
}