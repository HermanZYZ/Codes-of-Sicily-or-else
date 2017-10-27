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

MyPres mypres;//声明全局变量

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

	MyOstream& operator<<(int);//一个类也可以重载输入输出符
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
	MyOstream& operator<<(void (*manipulation)());//传进函数指针，在调用函数
	MyOstream& operator<<(MyOstream& (*manipulation)());

	friend MyOstream& myhex();//函数
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
		printf("%x", a);//十六进制输出 
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
	itoa(format, buffer,10);//itoa(int,char,int(进制))
	temp.insert(2, buffer);
	printf(temp.c_str(), a);//int printf ( const char * format, ... );
	return *this;

	//不能实现科学计数法
/*	if (!isfixed)
	{
		char str[100];
		sprintf_s(str, "%lf", a);//打印字符串，sicily上只支持sprintf
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

	myout << mypres(pres * 2);//setprecision(2),2位有效数字

	myout << e << myendl;

	myout << myfixed;//改为定点输出，即2位小数

	myout << e << myendl;



	int d = 17;

	myout << d << myendl;

	myout << myhex << d << myendl;
	getchar();

}



