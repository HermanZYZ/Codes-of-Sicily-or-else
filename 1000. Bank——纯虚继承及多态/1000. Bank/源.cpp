#include<iostream>
#include<cstring>
#include<string>

using namespace std;

class Bank
{
public:
	Bank(string _name)
	{
		name = _name;
	}
	string getName() const
	{
		return name;
	}
	virtual void printMessage() const = 0;

	virtual void deposit(double m) = 0;

	virtual void withdraw(double m) = 0;

	virtual double getMoney() const = 0;

protected:

	string name;
};

class ICBC : public Bank
{
public:

	ICBC(double _money = 0) :Bank("ICBC")
	{
		money = _money;
	}
	void printMessage() const
	{
		cout << "Welcome to Industrial and Commercial Bank of China" << endl;
	}

	void deposit(double m)
	{
		money += m;
	}

	void withdraw(double m)
	{
		if (money > m) money -= m;
		else money = 0;
	}

	double getMoney() const
	{
		return money;
	}

private:

	double money;
};

class ABC : public Bank
{
public:

	ABC(double _money = 0) :Bank("ABC")
	{
		money = _money;
	}

	void printMessage() const
	{
		cout << "Welcome to Agricultural Bank of China" << endl;
	}

	void deposit(double m)
	{
		money += m;
	}

	void withdraw(double m)
	{
		if (money > m) money -= m;
		else money = 0;
	}

	double getMoney() const
	{
		return money;
	}

private:

	double money;
};

class AccountManager
{
public:

	AccountManager(int _size);
	~AccountManager();
	void setBank(int i, Bank *bank);

	Bank* getBank(int i);

	void deposit(Bank *bank, double money);

	void withdraw(Bank *bank, double money);

	void transfer(Bank *bank1, Bank *bank2, double money);

	void printAccount() const;	//print the welcome message, bank name and money for each array element

private:

	Bank* *bankList;	//bank array, where each element is a (Bank*) type

	int size;	//the length of the bank array

};

AccountManager::AccountManager(int _size)
{
	size = _size;
	bankList = new Bank*[size];
}

AccountManager::~AccountManager()
{
	delete[]  bankList;
}

void AccountManager::setBank(int i, Bank * bank)
{
	bankList[i] = bank;
}

Bank * AccountManager::getBank(int i)
{
	return bankList[i];
}

void AccountManager::deposit(Bank * bank, double money)
{
	bank->deposit(money);
}

void AccountManager::withdraw(Bank * bank, double money)
{
	bank->withdraw(money);
}

void AccountManager::transfer(Bank * bank1, Bank * bank2, double money)
{
	double temp = bank1->getMoney();
	if (money > temp)
	{
		bank1->withdraw(temp);
		bank2->deposit(temp);
	}
	else
	{
		bank1->withdraw(money);
		bank2->deposit(money);
	}
}

void AccountManager::printAccount() const
{
	for (int i = 0; i < size; i++)
	{
		bankList[i]->printMessage();
		cout <<bankList[i]->getName()<<" "<< bankList[i]->getMoney() << endl;
	}
}

int main()

{

	AccountManager accountManager(2);
	Bank *bank1 = new ICBC(100);
	accountManager.setBank(0, bank1);
	Bank *bank2 = new ABC;
	bank2->printMessage(); 
	accountManager.setBank(1, bank2);
	accountManager.printAccount();
	accountManager.deposit(accountManager.getBank(0), 100);
	accountManager.deposit(accountManager.getBank(1), 100);
	accountManager.printAccount();
	accountManager.withdraw(accountManager.getBank(0), 50);
	accountManager.withdraw(accountManager.getBank(1), 50);
	accountManager.printAccount();
	accountManager.transfer(accountManager.getBank(0), accountManager.getBank(1), 500);
	accountManager.printAccount();


	system("pause");

	return 0;
}
