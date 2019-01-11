#include<cstdio>
#include<iostream>
using namespace std;

class node
{
public:
	int data;
	node* left;
	node* right;
	node* par;
	node() 
	{
		data = 0;
		left = right = par = NULL;
	}
	node(int d, node* l, node* r)
	{
		data = d;
		left = l;
		right = r;
	}
};

int cnt = 0;
void insert(int d, node* n)
{
	cnt++;
	if (d < n->data)
	{
		if (n->left == NULL)
		{
			node* newnode = new node();
			newnode->data = d;
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
		}
		else
		{
			insert(d, n->right);
		}
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int n;

	cin >> n;

	node* root = new node();
	
	int a;
	cin >> a;
	root->data = a;
	cout << cnt << "\n";
	for (int i = 1; i < n; i++)
	{
		cin >> a;
		insert(a, root);
		cout << cnt << "\n";
	}



	return 0;
}