#include<iostream>
#include<vector>
#include<cmath>
#include<iomanip>

const int inf=100000;

using namespace std;

double cpair(vector<double> vec)
{
	double delta;
	if(vec.size()==2)
	{
		delta = abs(vec[0]-vec[1]);
	}
	else if(vec.size()==1)
	{
		delta = inf;
	}
	else
	{
		vector<double> s1;
		vector<double> s2;
		double ma=0,mi=inf;
		for(int i=0;i<vec.size();i++)
		{
			if(vec[i]>ma)
				ma=vec[i];
			if(vec[i]<mi)
				mi=vec[i];
		}
		double p_=(ma+mi)/2;
		double p=0;
		double q=inf;
		for(int i=0;i<vec.size();i++)
		{
			if(vec[i]<=p_)
			{
				s1.push_back(vec[i]);
				if(vec[i]>p)
					p=vec[i];
			}
			else
			{
				s2.push_back(vec[i]);
				if(vec[i]<q)
					q=vec[i];
			}
		}
		double delta1=cpair(s1);
		double delta2=cpair(s2);
		delta=min(delta1,delta2);
		delta=min(delta,abs(p-q));
	}
	return delta;
}

int main()
{
	vector<double> vec;
	int n;
	while(cin>>n)
	{
		while(n--)
		{
			double temp;
			cin>>temp;
			vec.push_back(temp);
		}
		double delta=cpair(vec);
		cout<<fixed<<setprecision(6)<<delta<<endl;
		vec.clear();
	}
}
