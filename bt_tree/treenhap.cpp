#include <iostream>

using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
};

typedef node* tree;

void create_tree(tree &root)
{
    root = NULL;
}

tree getnode(int x)
{
    node *newele = new node;
    if(newele != NULL)
    {
        newele->data = x;
        newele->left = NULL;
        newele->right = NULL;
    }
    return newele;
}

void addnode(tree &root, int x)
{
    if(root)
    {   
        if(root->data == x) return;
        else if(root->data > x) addnode(root->left,x);
        else addnode(root->right,x);
        
    }
    else
    {
        root = getnode(x);
    }
}

void NLR(tree root)
{
    if(root)
    {
        cout << root->data << " ";
        NLR(root->left);
        NLR(root->right);
    }
}

void LNR(tree root)
{
    if(root)
    {
        LNR(root->left);
        cout << root->data << " ";
        LNR(root->right);
    }
}

void LRN(tree root)
{
    if(root)
    {
        LRN(root->left);
        LRN(root->right);
        cout << root->data << " ";
    }
}

tree find(tree &root, int x)
{
    if(root)
    {
        if(root->data == x) 
            return root;
        else if(root->data > x) find(root->left,x);
        else find(root->right,x);
    }
    return NULL;
}

void nutla(tree root)
{
    if(root)
    {
        if(root->left == NULL && root->right == NULL)
            cout << root->data << " ";        
        nutla(root->left);
        nutla(root->right);    
    }
}

void nut1con(tree root)
{
    if(root)
    {
        if(root->left == NULL ^ root->right == NULL)
            cout << root->data << " ";
        nut1con(root->left);
        nut1con(root->right);
    }
}

void nut2con(tree root)
{
    if(root)
    {
        if(root->left != NULL && root->right != NULL)
            cout << root->data << " ";
        nut2con(root->left);
        nut2con(root->right);
    }
}

void nuttrong(tree root, int x)
{
    if(root)
    {
        if(root->left != NULL && root->right != NULL && x != 0)
            cout << root->data << " ";
        nuttrong(root,x+1);
        nuttrong(root,x+1);
    }
}


void findplace(tree &root, node* &p) // tìm node phải nhất
{
    if(root->right != NULL)
        findplace(root->right,p);
    else
    {
        p->data = root->data;
        p = root;
        root = root->left;
    }
}

void findplace1(tree &root, node* &p) // tìm node trái nhất
{
    if(root->left != NULL)
        findplace1(root->left,p);
    else
    {
        p->data = root->data;
        p = root;
        root = root->right;
    }
}


void deletenode(tree root, int x)
{
   if(root)
   {
        if(root->data > x) deletenode(root->left,x);
        else if(root->data < x) deletenode(root->right,x);
        else if(root->data == x)
        {
            node *p = root;
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
                findplace(root->left,p);
                delete p;
            }
        }
        else cout << "Khong tim thay!\n"; 
   }
   else
   {
    cout << "khong tim thay!";
   }
}

void findmax(tree root)
{
    if(root)
    {
        if(root->right != NULL) findmax(root->right);
        else
            cout <<"Max: " <<root->data << " ";
    }
}



int main()
{
    tree L;
    create_tree(L);
    do
    {
        int x;
        cin >> x;
        if(x != -1)
            addnode(L,x);
        else
            break;
    } while (true);
    cout << "NLR: ";NLR(L);
    cout << "\nLNR: ";LNR(L);
    cout << "\nLRN: ";LRN(L);
    int xoa;
    cout << "\nXoa khoa: ";
    cin >> xoa;
    deletenode(L,xoa);
    cout << "LRN: ";LRN(L);
    cout << endl;
    findmax(L);
    return 0;
}