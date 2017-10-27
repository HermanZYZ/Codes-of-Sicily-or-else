#include<iostream>
#include<string>
using namespace std;
int main(){
	int n;
	cin>>n;
	while(n--){
		int base;
		cin>>base;
		string ss;
		int s1[102],s2[102];
		for(int i=0;i<102;++i)
		   s1[i]=s2[i]=0;
		cin>>ss;
		int j=0;
		for(int i=ss.length()-1;i>=0;--i){
			if(ss[i]>='A'&&ss[i]<='Z')
			   ss[i]=ss[i]-'A'+10+'0';
			s1[j++]=(ss[i]-'0');
		}
		
		cin>>ss;
		j=0;
		for(int i=ss.length()-1;i>=0;--i){
			if(ss[i]>='A'&&ss[i]<='Z')
			   ss[i]-=('A'-58);
			s2[j++]=(ss[i]-'0');
		}
		 int c=0;
		 for(int i=0;i<101;++i){
		 	 	s1[i]+=s2[i];
		 	 	c=s1[i]/base;
		 	 	s1[i]%=base;
		 	 	s1[i+1]+=c;
		 }
		 int i;
		 for(i=101;i>=0;--i)
		     if(s1[i]!=0)
		        break;
		for(;i>=0;--i)
		if(s1[i]<10)
		 cout<<s1[i];
		 else
		 cout<<(char)(s1[i]+'A'-10);
		 cout<<endl;
	}
}

