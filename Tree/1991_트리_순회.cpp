#include <iostream>
using namespace std;

class node
{
public:
    char data;
    node* left = NULL;
    node* right = NULL;

    node(char a)
    {
        data = a;
    }
};

node* nd[26];

void preorder(node* root)
{
    cout << root->data;
    if(root->left!=NULL)
        preorder(root->left);
    if(root->right!=NULL)
        preorder(root->right);
}

void inorder(node* root)
{
    if(root->left!=NULL)
        inorder(root->left);
    cout << root->data;
    if(root->right!=NULL)
        inorder(root->right);
}

void postorder(node* root)
{
    if(root->left!=NULL)
        postorder(root->left);
    if(root->right!=NULL)
        postorder(root->right);
    cout << root->data;
}

int main()
{
    cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    int n;

    cin >> n;

    while(n--)
    {
        char d,l,r;

        cin >> d >> l >> r;

        if(nd[d-65] == NULL)
            nd[d-65] = new node(d);

        if(l!='.')
        {
            if (nd[l - 65] != NULL)
            {
                nd[d - 65]->left = nd[l - 65];
            }
            else
            {
                nd[l - 65] = new node(l);
                nd[d - 65]->left = nd[l - 65];
            }
        }
        if(r!='.')
        {
            if (nd[r - 65] != NULL)
            {
                nd[d - 65]->right = nd[r - 65];
            }
            else
            {
                nd[r - 65] = new node(r);
                nd[d - 65]->right = nd[r - 65];
            }
        }

    }

    preorder(nd[0]);
    cout << "\n";
    inorder(nd[0]);
    cout << "\n";
    postorder(nd[0]);
    cout << "\n";

    return 0;
}