#include<cstdio>
#include<iostream>
using namespace std;

class node
{
public:
	int data = 0;
	node* left = NULL;
	node* right = NULL;
	node* par = NULL;

	node(){}
	node(int d, node* l, node* r)
	{
		data = d;
		left = l;
		right = r;
	}
};

void insert(int d, node* n)
{
	if (d < n->data)
	{
		if (n->left == NULL)
		{
			node* newnode = new node();
			newnode->data = d;
			newnode->par = n;
			n->left = newnode;
		}
		else
		{
			insert(d, n->left);
		}
	}
	else
	{
		if (n->right == NULL)
		{
			node* newnode = new node();
			newnode->data = d;
			n->right = newnode;
			newnode->par = n;
		}
		else
		{
			insert(d, n->right);
		}
	}
}

void transplant(node* p, node* i, node* c)
{
	if(u)
}

void delete()

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int n, m;

	cin >> n >> m;

	int a;
	for (int i = 0; i < n; i++)
	{
		cin >> a;

	}

	return 0;
}