#include <iostream>

using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
};

node *getnode(int x)
{
    node *newnode = new node;
    if(newnode != NULL)
    {
        newnode->data = x;
        newnode->left = NULL;
        newnode->right = NULL;
    }
    return newnode;
}

typedef node* tree;

void taocay(tree &root)
{
    root = NULL;
}

void addnode(tree &T, int x)
{
    if(T)
    {
        if(T->data == x) return;
        else if(x < T->data ) return addnode(T->left,x);
            else return addnode(T->right,x);
    }
    else
    {
        node *newroot = getnode(x);
        T = newroot;
    }
}

void inputtree(tree &mytree,int n)
{
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        addnode(mytree,x);
    }
    
}


int main()
{
    tree mytree;
    taocay(mytree);
    return 0;
}