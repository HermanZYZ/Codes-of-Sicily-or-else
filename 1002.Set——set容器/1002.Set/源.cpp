#include <iostream>
#include <set>

using namespace std;

class SetOperation
{
public:
	// Add any codes you want here
	SetOperation(int*, int, int*, int);
	set<int> Union();
	set<int> Intersetion();
private:
	// Add any codes you want here
	int Asize, Bsize;
	set<int> setA;
	set<int> setB;
};

SetOperation::SetOperation(int* a, int as, int* b, int bs)
{
	for (int i = 0; i < as; i++)
		setA.insert(a[i]);
	Asize = as;
	for (int i = 0; i < bs; i++)
		setB.insert(b[i]);
	Bsize = bs;
}

set<int> SetOperation::Union()
{
	set<int>unionSet;
	unionSet = setA;
	set<int>::iterator B = setB.begin();
	for (; B != setB.end(); B++)
	{
//		set<int>::iterator C;
//		C = setA.find((*B));
//		if (C == setA.end())
		unionSet.insert(*B);//set会自动识别相同元素并剔除
	}
	return unionSet;
}

set<int> SetOperation::Intersetion()
{
	set<int>unionSet;
	set<int>::iterator B = setB.begin();
	for (; B != setB.end(); B++)
	{
		set<int>::iterator C;
		C = setA.find((*B));
		if (C != setA.end())
			unionSet.insert(*B);
	}
	return unionSet;
}

void printSet(const set<int> &s) {

	bool first = true;

	for (set<int>::iterator it = s.begin(); it != s.end(); it++) {

		if (!first) cout << " ";

		else first = false;

		cout << *it;

	}

	cout << endl;

}



int main(int argc, char *argv[]) {

	int a[7] = { 8, 7, 5, 3, 1, 4, 6 };

	int b[4] = { 2, 3, 5, 4 };

	SetOperation s1(a, 7, b, 4);

	printSet(s1.Union());

	printSet(s1.Intersetion());

	system("pause");

	return 0;

}
