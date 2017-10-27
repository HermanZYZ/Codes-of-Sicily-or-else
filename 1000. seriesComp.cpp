#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

class seriesComp {

public:

    int n;	//n大于或等于1

    seriesComp(int n);

    int sum();

    int fib();

    double taylor(double x);

};

/******** this part should be submitted ********/

seriesComp::seriesComp(int n) {

	this->n=n;// your code

}
int seriesComp::sum() {
	return n*(n+1)/2;// your code

}

int seriesComp::fib() {
//	long long a=1,b=1;
//	long long ss=2;
//	for(int i=3;i<=n;i++)
//	{
//		int temp=b;
//		b=a+b;
//		a=temp;
//		ss+=b;
//	}
//	if(n==0) return 0;
//	if(n==1) return 1;
//	return ss;
	int temp=0,fibo=1,tol=0;
	for(int i=1;i<=n;i++)
	{
		int t;
		t=fibo;
		fibo+=temp;
		temp=t;
		tol+=temp;
	}
	return tol;
	// your code

}

double seriesComp::taylor(double x) {
	double tol=1;
	double j=1;
	for(int i=1;i<=n;i++)
	{
		j*=1.0*x/i;
		tol+=1.0*pow(-1,i)*j;
	}
	return tol;
	// your code (-1)^n * (x^n) / (n!)

}

/******** this part should be submitted ********/

 

int main() {

	int T;

	int n;

	double x;

	

	cin >> T;

	while (T--) {

		cin >> n >> x;

		seriesComp mySeriesComp(n);

		cout << mySeriesComp.sum() << ' ' << mySeriesComp.fib() << ' ' << mySeriesComp.taylor(x) << endl; 

	}

	

	return 0;

} 
