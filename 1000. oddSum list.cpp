#include <stdio.h>

#include <algorithm>

using namespace std;

 

struct ListNode{

	int val;

	ListNode *next;

	ListNode():val(0), next(NULL){};

	ListNode(int val):val(val), next(NULL){}

};

 

//you just need submit this function

int oddSum(ListNode *head){

	int sum=0;
	ListNode* t=head;
	while(t)
	{
		sum+=t->val;
		t=t->next;
		t=t->next;
	}
	return sum; //place your code here

}

 

int main(){

	int size = rand() % 1000 + 1;

	ListNode *dummy = new ListNode(0);

	ListNode *prev = dummy;

	int middleValue = 0, sum = 0;

	for (int i = 1; i <= size; i++){

		int val = rand() % 100000;

		if (i % 2) sum += val;

		ListNode *temp = new ListNode(val);

		prev->next = temp;

		prev = temp;

	}

 

	if (sum == oddSum(dummy->next)){

		puts("YES");

	} else{

		puts("NO");

	}

	return 0;

}
