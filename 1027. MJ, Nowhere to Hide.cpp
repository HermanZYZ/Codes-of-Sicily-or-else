#include<iostream>
#include<map>

using namespace std;

int main()
{
	int n;
	while(cin>>n && n)
	{
		string id,ad;
		map<string,string> dic;
		map<string,string> result;
		map< string, string >::iterator it=dic.begin();
		for(int i=0;i<n;i++)
		{
			cin>>id>>ad;
			it = dic.find(ad);
			if(it==dic.end())
			{
				dic.insert(pair<string,string>(ad,id));
			}
			else
			{
				result.insert(pair<string,string>((*it).second,id));
			}
		}
		for(it=result.begin();it!=result.end();it++)
		{
			cout<<(*it).second<<" is the MaJia of "<<(*it).first<<endl;
		}
		cout<<endl;
	}
}
