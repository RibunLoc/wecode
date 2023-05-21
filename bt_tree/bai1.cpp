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
void LNR(Tree root) 
{
    if(root)
    {
        LNR(root->left);
        cout<< root->data<< " ";
        LNR(root->right);
    }
}

Node *Search(Tree &root,int x)
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

int minValue(Tree root)
{
    if(root->left != NULL)
        return minValue(root->left);
    else
        return root->data;
}

int maxValue(Tree root)
{
    if(root->right != NULL)
        return maxValue(root->right);
    else
        return root->data;
} 


int main()
{
	Tree T = NULL;
	inputTree(T);
	cout<<"LNR: "; LNR(T); cout<<endl;


    int x; cout<<"\nEnter the element you want to find: ";cin>>x;
    Node *p=Search(T,x);
    if (p) cout<< "Found";
    else cout<<"Not found";
    cout<<"\nMinimum value in BTS is "<<minValue(T);
    cout<<"\nMinimax value in BTS is "<<maxValue(T);


	return 0;
}
