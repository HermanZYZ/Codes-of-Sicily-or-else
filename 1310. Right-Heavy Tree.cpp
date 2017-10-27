//1310. Right-Heavy Tree

#include <bits/stdc++.h>

using namespace std;

struct Tree
{
	int value;
	struct Tree *left;
	struct Tree *right; 
	Tree()
	{
		left=right=NULL;
	}
};

Tree *head=NULL;

void build(int n)
{
	int a;
	Tree* temp=head;
	while(n--)
	{
		//printf("%d ",n );
		scanf(" %d",&a);
		temp=head;
		if(head==NULL)
		{
			head = new Tree;
			head->value=a;
			head->left=NULL;
			head->right=NULL;
			temp=head;
		}
		else
		{
			while(1)
			{
				if(a>temp->value)
					if(temp->right==NULL)
					{
						Tree* t = new Tree;
						t->value=a;
						temp->right=t;
						break;
					}
					else
						temp=temp->right;
				else if(a<temp->value || a==temp->value)
					if(temp->left==NULL)
					{
						Tree* t = new Tree;
						t->value=a;
						temp->left=t;
						break;
					}
					else
						temp=temp->left;
				else;
			}
		}
	}
}

//树的三种遍历方式
void Inorder(Tree* e) {
	if(!e)
		return;
	// if (e->left == NULL && e->right== NULL) {
	// 	cout << " "<< e->value;
	// 	return;
	// }
	if (e) {
		Inorder(e->left);
		printf(" %d", e->value);
		//cout << " " << e->value;
		Inorder(e->right);
		}
}
void Preorder(Tree* e) {
	if(!e)
		return;
	// if (e->left == NULL && e->right== NULL) {
	// 	cout << " "<< e->value;
	// 	return;
	// }
	if (e) {
		printf(" %d", e->value);
		Preorder(e->left);
		Preorder(e->right);
	}
}
void Postorder(Tree* e) {
	if(!e)
		return;
	// if (e->left == NULL && e->right== NULL) {
	// 	cout << " "<< e->value;
	// 	return;
	// }
	if (e) {
		Postorder(e->left);
		Postorder(e->right);
		printf(" %d", e->value);
	}
}

void Free(Tree* e)
{
	if(!e)
		return;
	if (e) {
		Free(e->left);
		Free(e->right);
		delete e;
	} 
}

int main()
{
	int n;
	bool flag=false;
	while(~scanf("%d",&n))
	{
		if(flag)
			printf("\n");
		flag=true;
		head=NULL;
		build(n);
		printf("Inorder:");
		Inorder(head);
		printf("\n");

		printf("Preorder:");
		Preorder(head);
		printf("\n");

		printf("Postorder:");
		Postorder(head);
		printf("\n");
		Free(head);
	}
}
