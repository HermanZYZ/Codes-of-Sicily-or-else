#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
bool isAnagram(const char * const s1, const char * const s2)  
{
	string ss1,ss2;
	for(int i=0;i<strlen(s1);i++)
		ss1+=s1[i];
	for(int i=0;i<strlen(s2);i++)
		ss2+=s2[i];
	//return ss1==ss2?true:false;
	//if(ss1==ss2) return true;
	//else return false;
	sort(ss1.begin(),ss1.end());
	sort(ss2.begin(),ss2.end());
	return ss1==ss2;
}
int main()
{
	char s1[20],s2[20];
	cin>>s1>>s2;
	cout<<isAnagram(s1,s2);
}
