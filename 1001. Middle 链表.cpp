#include <stdio.h>

#include <algorithm>

//#include<list>

using namespace std;

 

struct ListNode{

	int val;

	ListNode *next;

	ListNode():val(0), next(NULL){};

	ListNode(int val):val(val), next(NULL){}

};

 

//you just need submit this function

int middleItem(ListNode *head)
{
	ListNode *tmp1=head, *tmp2=head;
	while(tmp2->next!=NULL)
	{
		tmp2=tmp2->next;
		if(tmp2->next)
		{
			tmp1=tmp1->next;
			tmp2=tmp2->next;			
		}
	}
	return tmp1->val;
}

 

int main(){

	int size = rand() % 100000 + 1;

	ListNode *dummy = new ListNode(0);

	ListNode *prev = dummy;

	int middleValue = 0;
	

	for (int i = 0; i < size; i++){

		int val = rand() % 100000;

		if (i == (size - 1) / 2) middleValue = val;

		ListNode *temp = new ListNode(val);

		prev->next = temp;

		prev = temp;

	}
 

	if (middleItem(dummy->next) == middleValue){

		puts("YES");

	} else{

		puts("NO");

	}
	return 0;

}
