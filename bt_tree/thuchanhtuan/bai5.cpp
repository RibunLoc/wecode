/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include <iostream>
using namespace std;

//###INSERT CODE HERE -
struct node
{
    int data;
    node* left;
    node* right;
};

typedef node* Tree;
node* getnode (int x)
{
    node *newele = new node();
    if(newele != NULL)
    {
        newele->data = x;
        newele->left = NULL;
        newele->right = NULL;
    }
    return newele;
}

void insertTree(Tree &root, int x)
{
    if(root)
    {
        if(root->data > x)
            insertTree(root->left,x);
        else if(root->data < x)
            insertTree(root->right,x);
        else
            return;
    }
    else
    {
        root = getnode(x);
    }
}

void inputTree(Tree &T)
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x; cin >> x;
        insertTree(T,x);
    }
    
}

void LNR(Tree T)
{
    if(T)
    {
        LNR(T->left);
        cout << T->data << " ";
        LNR(T->right);
    }
}

Tree removeLeafs(Tree &T)
{
    if(T)
    {       
        
        if(T->left == NULL && T->right == NULL)
            T = NULL;
        else
        {
            removeLeafs(T->left);
            removeLeafs(T->right);
        }
    }
    return T;
}

int main()
{
	Tree T = NULL;
	inputTree(T);
	cout<<"LNR: "; LNR(T);
	T = removeLeafs(T);
	cout<<"\nUpdated Tree: \n";
	cout<<"LNR: "; LNR(T);
	return 0;
}



