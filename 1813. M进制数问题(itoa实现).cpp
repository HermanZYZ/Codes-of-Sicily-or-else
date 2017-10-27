#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cstdio>

using namespace std;


char* my_itoa(int num,char* str,int radix)
{
	//������ 
	char index[]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	unsigned unum;
	int i=0,j,k;
	
	//ȷ��umum��ֵ
	if(radix==10 && num<0)//ʮ���Ƹ��� 
	{
		unum=(unsigned)-num;
		str[i++]='-';
	} 
	else
		unum=(unsigned)num;//������� 
	//���� 
	do{
		str[i++]=index[unum%(unsigned)radix];
		unum/=radix;
	}while(unum);
	
	str[i]='\0';
	//ת�� 
	if(str[0]=='-')
		k=1;//ʮ���Ƹ��� 
	else
		k=0;
	//��֤��num��16~255֮�䣬radix����16�ǣ�Ҳ�ܵõ���ȷ���	
	for(j=k;j<(i-1)/2.0+k;j++)
	{
		num=str[j];
		str[j]=str[i-j-1+k];
		str[i-j-1+k]=num;
	}
	return str;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int base;
		cin>>base;
		string a,b;
		cin>>a>>b;
		long long c,d;
		char* stop;
		c=strtol(a.c_str(),&stop,base);
		d=strtol(b.c_str(),&stop,base);
		
//		cout<<c<<endl<<d<<endl; 
		
		int p=c/d,q=c%d; 
		char f[105];
		char e[105];
		my_itoa(p,f,base);
		my_itoa(q,e,base);
		cout<<f<<endl;
		cout<<e<<endl;
//		for(int i=0;i<strlen(f);i++) 
//		{
//			if(f[i]>='a' && f[i]<='z')
//			{
//				f[i]-=32;
//				cout<<f[i];
//			}
//			else cout<<f[i];
//		}
//		cout<<endl;
//		for(int i=0;i<strlen(e);i++) 
//		{
//			if(e[i]>='a' && e[i]<='z')
//			{
//				e[i]-=32;
//				cout<<e[i];
//			}
//			else cout<<e[i];
//		}
//		cout<<endl;
	}
}
