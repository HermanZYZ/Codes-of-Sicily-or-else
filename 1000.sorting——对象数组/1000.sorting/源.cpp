#include <iostream>

#include <string>

struct TaoBaoItem
{

	int price;

	int volume_of_sales;

};

class SortInterface
{
public:

	virtual ~SortInterface() {};
	virtual void DoSort(TaoBaoItem item[], int size) = 0;

};

#include<algorithm>
using namespace std;
class SortByPrice : public SortInterface
{
public:

	virtual void DoSort(TaoBaoItem item[], int size);

};

class SortBySales : public SortInterface
{
public:

	virtual void DoSort(TaoBaoItem item[], int size);

};

class TaoBao
{
public:

	TaoBao(SortInterface* strategy);

	void SetSortStrategy(SortInterface* strategy);

	// Use current strategy_ to do the sort.

	void sort(TaoBaoItem item[], int size);

private:

	SortInterface *strategy_;

};

void SortByPrice::DoSort(TaoBaoItem item[], int size)
{
	for (size_t i = 0; i < size; i++)
	{
		for (int j = i ; j < size; j++)
		{
			if (item[i].price < item[j].price)
				swap(item[j], item[i]);
		}
	}
	return;
}

void SortBySales::DoSort(TaoBaoItem item[], int size)
{
	for (size_t i = 0; i < size; i++)
	{
		for (int j = i; j < size; j++)
		{
			if (item[i].volume_of_sales < item[j].volume_of_sales)
				swap(item[j], item[i]);
		}
	}
	return;
}

TaoBao::TaoBao(SortInterface * strategy)
{
	strategy_ = strategy;
}

void TaoBao::SetSortStrategy(SortInterface * strategy)
{
	strategy_ = strategy;
}

void TaoBao::sort(TaoBaoItem item[], int size)
{
	strategy_->DoSort(item, size);
}

void printItem(TaoBaoItem arr[], int size)

{

	for (int i = 0; i < size; i++)

		cout << arr[i].price << " " << arr[i].volume_of_sales << endl;

}



int main(int argc, char *argv[])

{

	TaoBaoItem item[4] = {

		{ 1, 2 },

		{ 2, 3 },

		{ 5, 1 },

		{ 3, 10 }

	};

	SortByPrice price;

	SortBySales sales;



	TaoBao taobao(&price);

	taobao.sort(item, 4);

	printItem(item, 4);



	taobao.SetSortStrategy(&sales);

	taobao.sort(item, 4);

	printItem(item, 4);



	system("pause");
	return 0;
}
