#include <iostream>

#include <vector>

using namespace std;

const int maxObserver = 10;

class Observer

{

public:

	virtual ~Observer() {}

	virtual void notify() = 0;

};

//Subject类的声明如下：

class Subject
{
public:

	Subject();

	//add observer to observerList

	void addObserver(Observer *observer);

	//remove observer from observerList

	void removeObserver(Observer *observer);

	//send subject changed message

	void change();

private:

	Observer* observerList[maxObserver];

	int numObserver;

};

//在类ObserverA中的notify函数中输入以下信息（一行）：

//ObserverA is notified that Subject changed.

//同理，类ObserverB为：

//ObserverB is notified that Subject changed.

class ObserverA : public Observer
{
public:
	void notify();

private:

};

void ObserverA::notify()
{
	cout << "ObserverA is notified that Subject changed." << endl;
}

class ObserverB : public Observer
{
public:
	void notify();

private:

};

void ObserverB::notify()
{
	cout << "ObserverB is notified that Subject changed." << endl;
}

Subject::Subject()
{
	numObserver = 0;
}

void Subject::addObserver(Observer * observer)
{
	observerList[numObserver] = observer;
	numObserver++;
}

void Subject::removeObserver(Observer * observer)
{
	for (int i = 0; i<numObserver; i++)
	{
		if (observerList[i] == observer)
		{
			if (i == numObserver - 1) numObserver--;
			else
			{
				for (int j = i; j<numObserver - 1; j++)
				{
					observerList[j] = observerList[j + 1];
				}
				numObserver--;
			}
		}
	}

}

void Subject::change()
{
	for (size_t i = 0; i < numObserver; i++)
	{
		observerList[i]->notify();
	}
}

int main(int argc, char *argv[])

{

	ObserverA a;

	ObserverB b;

 

	Subject subject;

	subject.addObserver(&a);

	subject.addObserver(&b);

	subject.change();




	return 0;

}
