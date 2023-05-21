#include <iostream>

using namespace std;

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

void NLR(Tree root)
{
    if(root)
    {
        cout << root->data << " ";
        NLR(root->left);
        NLR(root->right);
    }
}


Node* xoaytrai(Tree root)
{
    Node* temp = root; //temp = node15

    Node* newroot = temp->right; // newroot = node12

    temp->right = newroot->left; // NULL

    newroot->left = temp; 

    root = newroot;
    temp = NULL;
    delete temp;
    

    return newroot;
}

int main()
{
    Tree T = NULL;
    inputTree(T);
    cout << "NLR: "; NLR(T);
    cout << endl;
    if(T == NULL)
    {
        cout<< "\nKhong the xoay vi cay rong"<<endl;;
    }else if(T->right == NULL)
    {
        cout<< "\nKhong the xoay trai vi khong co nut con ben phai"<<endl;
    }
    else
    {
        T = xoaytrai(T);
    }
    cout << "NLR: ";NLR(T);

    return 0;
}