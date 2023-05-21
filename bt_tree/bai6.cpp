/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include <iostream>
using namespace std;

//###INSERT CODE HERE -

struct Node
{
    int data;
    Node *left;
    Node *right;
};

typedef Node* Tree;

Node* getnode(int x)
{
    Node *p = new Node;
    if(p != NULL)
    {
        p->data = x;
        p->left = NULL;
        p->right = NULL;
    }
    return p;
}

void AddNode(Tree &root, int x)
{
    if(root != NULL)
    {
        if(root->data == x) return; // tìm thấy không thêm
        if(x < root->data) // thêm bên trái 
            AddNode(root->left, x);
        else
            AddNode(root->right,x);
    }
    else
    {
        root = getnode(x); // đã tìm thấy
    }
}

void inputTree(Tree &T)
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        AddNode(T,x);
    }  
} 

void NLR(Tree root)
{
    if(root)
    {
        cout << root->data << " ";
        NLR(root->left);
        NLR(root->right);
    }
}


void findreplace(Tree &root, Node *&p) // tìm khóa trái nhất 
{
    if(root->left != NULL)
        findreplace(root->left, p);
    else
    {
        p->data = root->data;
        p = root;
        root = root->right;
    }
}

void findreplace1(Tree &root, Node *&p)
{
    if(root->right != NULL)
        findreplace1(root->right,p);
    else
    {
        p->data = root->data;
        p = root;
        root = root->left;
    }
}
void deleteNode1(Tree &root, Tree &p)
{
    if(root == p)
    {
            if(root->left == NULL && root->right == NULL)
            {
                root = NULL;
                delete p;
            }
            else if(root->left != NULL && root->right == NULL)
            {
                root = root->left;
                delete p;
            }
            else if(root->right != NULL && root->left == NULL)
            {
                root = root->right;
                delete p;
            }
            else
            {
                findreplace1(root->left,p); 
                delete p;
            }

    }     
    else if (p->data < root->data) {
            deleteNode1(root->left, p);
        } else {
            deleteNode1(root->right, p);
        }
}

Tree Search(Tree root,int x)
{
    if(root)
    {
        if(root->data > x) return Search(root->left,x);
        else if(root->data < x) return Search(root->right,x);
        else if(root->data == x) return root;
        else return NULL;
    }
    return NULL;
}

void deleteNode(Tree &root, int x)
{

    
    Tree p = Search(root,x);
    char y;
    if(p)
    {
        cout<<"\nDo you want to delete "<<x<< "?(y/n): ";
        cin >> y;
        if(y == 'Y' || y == 'y')
            deleteNode1(root,p);
    }
    else
        cout << "Not found";
}

int main()
{
	Tree T = NULL;
	inputTree(T);
	cout<<"NLR: "; NLR(T);
    int x; cout<<"\nEnter the element you want to delete: ";cin>>x;
    deleteNode(T,x);
    cout<<"\nNLR: "; NLR(T);

	return 0;
}
