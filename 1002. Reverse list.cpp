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

ListNode* reverse(ListNode *head, int m, int n){

	ListNode* t=head;
	int a[100000];
	int i;
	for(i=0;t!=NULL;i++)
	{
		a[i]=t->val;
		t=t->next;
	} 
	for(n=n-1,m=m-1;n>m;m++,n--)
	{
		swap(a[m],a[n]);
	}
	ListNode* aaa = new ListNode;
	t=aaa;
	for(int j=0;j<=i;j++)
	{
		t->val=a[j];
		t->next=new ListNode;
		t=t->next;
	}//place your code here
	return aaa;
}

 

bool check(ListNode *head, int arr[], int size){

	for (int i = 0; i < size; i++){

		if (!head) return false;

		if (head->val != arr[i]) return false;

		head = head->next;

	}

	return true;

}

 

int main(){

	int size = rand() % 100000 + 1;

	int m = rand() % size + 1, n = rand() % size + 1;

	if (m > n) swap(n, m);

	ListNode *dummy = new ListNode(0);

	ListNode *prev = dummy;

	int arr[size + 1];

	for (int i = 0; i < size; i++){

		int val = rand() % 100000;

		arr[i] = val;

		ListNode *temp = new ListNode(val);

		prev->next = temp;

		prev = temp;

	}

 

	ListNode *head = reverse(dummy->next, m, n);

	reverse(arr + m - 1, arr + n);

	if (check(head, arr, size)){

		puts("YES");

	} else{

		puts("NO");

	}

	return 0;

}
