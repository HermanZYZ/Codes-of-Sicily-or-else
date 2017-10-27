#include <bits/stdc++.h>

using namespace std;

const int MAX = 1000001;
bool composite[MAX];
int prime[MAX],Index=0;

void Prime()
{
	memset(composite,false,sizeof(composite));
	for(int i = 2;i < MAX;i++)
	{
		if(composite[i])
			continue;
		prime[Index++]=i;
		for( int j = 2*i;j < MAX;j+=i)
			composite[j] = 1;
	}
}

int main()
{
	string k;
	int l;
	Prime();
	while(cin>>k>>l && k!="0" && l)
	{
		bool flag=true;
		int mod=0;
		 for(int i=0;i<Index;i++)
		 {
		 	mod=0;
		 	for(unsigned int j=0;j<k.size();j++)
		 		mod=(mod*10+(k[j]-'0'))%prime[i];
		 	if(mod==0 && prime[i]<l)
		 	{
		 		flag=false;
		 		mod=prime[i];
		 		break;
		 	}
		 	else if(prime[i]>=l)
		 		break;
		 }
		 if(flag)
		 	cout<<"GOOD"<<endl;
		 else
		 	cout<<"BAD "<<mod<<endl;
	}
}