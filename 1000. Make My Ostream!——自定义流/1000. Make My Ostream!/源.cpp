#include<cstdio>
#include<cmath>
#include<string>
#include<cstdlib>
using namespace std;

class MyPres
{
public:
	MyPres()
	{
		pres = 0;
	}
	MyPres& operator()(int n)
	{
		if (n > 6) n = 6;
		pres = n;
		return *this;
	}
	int getPres()
	{
		return pres;
	}

private:
	int pres;
};

MyPres mypres;//����ȫ�ֱ���

/*
struct _Setprecision
{
	int _M_n;
}mypres;
*/

class MyOstream
{
public:
	MyOstream();

	MyOstream& operator<<(int);//һ����Ҳ�����������������
	MyOstream& operator<<(double);
	MyOstream& operator<<(const char);
	MyOstream& operator<<(const char*);
//	MyOstream& operator<<(void (*manipulation)(MyOstream&))
//	{
//		manipulation(*this);
//		return *this;
//	}
//
//	friend void myendl(MyOstream& out) 
//	{
//		printf("\n");
//		return;
//	}
//	friend void myfixed(MyOstream& out)
//	{
//		out.isfixed = true;
//		out.format = 2;
//	}
//	friend void myhex(MyOstream& out)
//	{
//		out.ishex = true;
//	}
//	MyOstream& operator<<(MyPres& pres)
//	{
//		this->format = pres.getPres();
//		return *this;
//	}
	MyOstream& operator<<(MyPres);
	MyOstream& operator<<(void (*manipulation)());//��������ָ�룬�ڵ��ú���
	MyOstream& operator<<(MyOstream& (*manipulation)());

	friend MyOstream& myhex();//����
	friend MyOstream& myfixed();

private:
	bool ishex;
	bool isfixed;
	int format;
}myout;

MyOstream::MyOstream()
{
	ishex = false;
	isfixed = false;
	format = 6;
}

MyOstream & MyOstream::operator<<(int a)
{
	if (ishex)
		printf("%x", a);//ʮ��������� 
	else
		printf("%d", a);
	ishex = false;
	return *this;
}

MyOstream & MyOstream::operator<<(double a)
{
	string temp;
	if (isfixed)	temp = "%.llf";
	else temp = "%.g";
	char buffer[100];
	itoa(format, buffer,10);//itoa(int,char,int(����))
	temp.insert(2, buffer);
	printf(temp.c_str(), a);//int printf ( const char * format, ... );
	return *this;

	//����ʵ�ֿ�ѧ������
/*	if (!isfixed)
	{
		char str[100];
		sprintf_s(str, "%lf", a);//��ӡ�ַ�����sicily��ֻ֧��sprintf
		for (int temp = 0, i = 0; temp < format;i++)
		{
			printf("%c", str[i]);
			if (str[i] != '.') temp++;
		}
	}
	else
	{
		printf("%.*lf", format, a);
		format = 6;
	}
	isfixed = false;
	return *this;
*/
}

MyOstream & MyOstream::operator<<(const char a)
{
	printf("%c", a);
	return *this;
}

MyOstream & MyOstream::operator<<(const char *a)
{
	printf("%s", a);
	return *this;
}


MyOstream & MyOstream::operator<<(MyPres a)
{
	format = a.getPres();
	return *this;
}

MyOstream & MyOstream::operator<<(void(*manipulation)())
{
	manipulation();
	return *this;
}

MyOstream & MyOstream::operator<<(MyOstream &(*manipulation)())
{
	manipulation();
	return *this;
}

void myendl()
{
	printf("\n");
	return ;
}

MyOstream & myhex()
{
	myout.ishex = true;
	return myout;
}


MyOstream & myfixed()
{
	myout.isfixed = true;
	return myout;
}


int main()

{

	const char *test1 = "Test char";

	myout << test1 << myendl;

	myout << test1[0] << myendl;



	double e = 6.12345;

	int pres = 1;

	myout << mypres(pres * 2);//setprecision(2),2λ��Ч����

	myout << e << myendl;

	myout << myfixed;//��Ϊ�����������2λС��

	myout << e << myendl;



	int d = 17;

	myout << d << myendl;

	myout << myhex << d << myendl;
	getchar();

}



