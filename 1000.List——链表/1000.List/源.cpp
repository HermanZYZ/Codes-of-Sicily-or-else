#include<iostream>
#include<list>
#include<string>

using namespace std;

int main()
{
	list<int> mylist;
	int num;
	while (cin >> num)
	{
		while (num--)
		{
			string s;
			int temp;
			cin >> s;
			if (s == "push_back")
			{
				cin >> temp;
				mylist.push_back(temp);
			}
			else if (s == "push_front")
			{
				cin >> temp;
				mylist.push_front(temp);
			}
			else if (s == "pop_back")
			{
				mylist.pop_back();
			}
			else if (s == "pop_front")
				mylist.pop_front();
			else if (s == "print")
			{
				cout << "List:" << endl;
				for (list<int>::iterator it = mylist.begin(); it != mylist.end(); it++)
					cout << *it << endl;
			}
		}
		mylist.clear();
	}
	return 0;
}