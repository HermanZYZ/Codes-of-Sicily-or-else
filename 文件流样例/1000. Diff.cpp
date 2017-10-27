#include<iostream>
#include<fstream>//文件流头文件 

using namespace std;

int main()
{
	string f1,f2,f3;
	string file1,file2;
	while(cin>>f1>>f2>>f3)
	{
		ifstream infile1(f1.c_str());
	//	infile1.open(f1.c_str());
		ifstream infile2(f2.c_str());
		ofstream outfile3(f3.c_str());//声明输出文件流 
		
//		infile1>>file1;//提取流内容 并刷新缓冲区 
//	//	getline(infile1,file1);//读取内容 （另一方法） 
//		infile2>>file2;
		
		long long size1=file1.size(),size2=file2.size();
		
		if(size1>size2)
			swap(size1,size2);
		
		int position=-1;
		
		//可以读取换行内容 
		do
		{
			char a=infile1.get() ,b=infile2.get();
//			cout<<a<<" "<<b<<"*";
			if(a!=b)
			{
				outfile3<< "Different " <<position+1;
				break;
			}
			position++;
		}while(!infile1.eof() && !infile2.eof());
		
//		for(int i=0;i<size1;i++)//不能读取换行内容 
//		{
//			if(file1[i] != file2[i])
//			{
//				outfile3<< "Different " <<i;
//				position=i;
//				break;
//			}
//		}

		if(size1!=size2 && position==size1-1)
		{
			outfile3<< "Different " <<size1;
			position=size1;
		} 
		if(position==-1)
			outfile3<< "Same" ;
			
		infile1.close(); //关闭文件 
		infile2.close(); 
		outfile3.close();//不关掉不能读取
		 
		//下面的是测试代码，就是看看内容是否输出保存到相应文件中 
		fstream infile3;
		char file3;
		infile3.open(f3.c_str());
		//infile3>>file3;遇到空格会自动结束 

//      只能一个个读取字符		
//		while(infile3.get(file3))
//			cout<<file3;
//		cout<<endl;

//      有长度限制		
//		char f[20]
//		infile3.getline(f,20)
//		cout<<f<<endl;
		 
		string f;
		getline(infile3,f) ;
		cout<<f<<endl;
		infile3.close();
		//File1.txt File2.txt File3.txt  输入内容 
		//File1.txt File2.txt File4.docx
	}
	
	return 0;
}
