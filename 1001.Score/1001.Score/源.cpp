#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

class Student {
public:
	bool operator < (const Student b) const
	{
		return score<b.score;
	}
	friend istream& operator >>(istream& is,Student& ano)
	{
		is >> ano.name >> ano.score;
		return is;
	}
	friend ostream& operator <<(ostream& os, Student& ano)
	{
		os << ano.name <<" "<< ano.score;
		return os;
	}
private:
	int score;
	string name;
};

int main()
{
	Student a;
	vector<Student> myVector;
	int n, m;
	while (cin >> n >> m)
	{
		while (n--)
		{
			cin >> a;
			myVector.push_back(a);
		}
		sort(myVector.begin(), myVector.end());
		while (m--)
		{
			int i;
			cin >> i;
			cout << myVector[i-1] << endl;
		}
		myVector.clear();
	}
	
}
