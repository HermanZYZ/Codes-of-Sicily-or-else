#include<iostream>
#include<queue>

using namespace std;


string pre,in;
int index;

struct tree
{
	char c;
	struct tree* left;
	struct tree* right;
};

void rebuild(struct tree* &root,int begin,int end)
{
	if(index>=pre.size() || begin>end)
	{
		return;
	}
	else 
	{
		root=new tree();
		root->c=pre[index];
		root->left=NULL;
		root->right=NULL;
		int i=in.find(pre[index++]);
		rebuild(root->left,begin,i-1);
		rebuild(root->right,i+1,end);
	}
}

void bsf(struct tree *&root)
{
	queue<tree*> q;
   	q.push(root);
    while(!q.empty())
    {
        tree *r = q.front();
        q.pop();
        cout<<r->c;
       	if(r->left) q.push(r->left);
        if(r->right) q.push(r->right);
    }
    cout<<endl;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		index=0;
		cin>>pre>>in;
		struct tree* root=NULL;
		rebuild(root,0,pre.size());
		bsf(root);
	}
}
