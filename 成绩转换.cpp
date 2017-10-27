#include<iostream>
using namespace std;
int main()
{
	int score;
	while(cin>>score)
	{
		if(score<0 || score>100)
		cout<<"Score is error!"<<endl;
		else
		{
			if(score>=90 && score<=100)
			cout<<"A"<<endl;
			if(score>=80 && score<=89)
			cout<<"B"<<endl;
			if(score>=70 && score<=79)
			cout<<"C"<<endl;
			if(score>=60 && score<=69)
			cout<<"D"<<endl;
			if(score>=0 && score<=59)
			cout<<"E"<<endl;
		}
	}
	return 0;
}
