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
    node *p = new node;
    if(p != NULL)
    {
        p->data = x;
        p->left = NULL;
        p->right = NULL;
    }
    return p;
}

typedef node* tree;

void createTree(tree &root)
{
    root = NULL;
}

void AddNode(tree &root, int x)
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

void LNR(tree root) //Duyệt trung tự (LNR): duyệt trung tự cây con trái, duyệt nút gốc, duyệt trung tự cây con phải.
{
    if(root)
    {
        LNR(root->left);
        cout<< root->data<< " ";
        LNR(root->right);
    }
}

void NLR(tree root) //Duyệt tiền tự (NLR): duyệt nút gốc, duyệt tiền tự cây con trái, duyệt tiền tự cây con phải.
{
    if(root != NULL)
    {
        cout << root->data<<" ";
        NLR(root->left);
        NLR(root->right);
    }
    return;
}

void LRN(tree root) //duyệt hậu tự cây con trái, duyệt hậu tự cây con phải, duyệt nút gốc.
{
    if(root != NULL)
    {
        LRN(root->left);
        LRN(root->right);
        cout<<root->data<<" ";
    }
    return;
}

void nutla(tree root)
{
    if(root != NULL)
    {
        if(root->left == NULL && root->right == NULL)
            cout << root->data<<" ";
        nutla(root->left);
        nutla(root->right);
    }

}

void nuttrong(tree root, int x)
{
    if(root != NULL)
    {
        if((root->left != NULL || root->right != NULL) && x!= 0)
            cout << root->data << " ";
        nuttrong(root->left,x+1);
        nuttrong(root->right,x+1);
    }
}

void nut1con(tree root)
{
    if(root != NULL)
    {
        if((root->left == NULL && root->right != NULL)||(root->left != NULL && root->right == NULL))
            cout << root->data <<" ";
        nut1con(root->left);
        nut1con(root->right);
    }
}

void nut2con(tree root)
{
    if(root != NULL)
    {   
        
        if(root->left != NULL && root->right != NULL)
            cout<<root->data << " ";
        nut2con(root->left);
        nut2con(root->right);
    }
}

node *find(tree l, int x)
{
    if(l != NULL)
    {
        if(l->data == x) 
            return l;
        if(x < l->data)
            return find(l->left,x);
        else return find(l->right,x);
    }
    return NULL;
}

void findreplace1(tree &root, tree &p) //Tìm Node trái nhất
{
    if(root->left != NULL)
    {
            findreplace1(root->left,p);
    }
    else
    {
        p->data = root->data;
        p = root;
        root = root->right;
    }
}



void findreplace2(tree &root, tree &p) //Tìm Node phải nhất
{
    if(root->right != NULL)
    {
        findreplace2(root->right,p);
    }
    else
    {
        p->data = root->data;
        p = root;
        root = root->left;
    }
}

node *deletenode(tree &l , int x)
{
    if(l != NULL)
    {
        if(x < l->data) deletenode(l->left,x);
        else if(x > l->data) deletenode(l->right,x);
            else
            {   
                node *p = l;
                if(l->left == NULL && l->right == NULL)
                {
                    l = NULL;
                    delete p;
                }
                else if(l->left == NULL)
                {
                    l = l->right;
                    delete p;
                }else if(l->right == NULL)
                        {
                            l = l->left;
                            delete p;
                        }else
                        {
                            findreplace2(p->left,p); // tìm khóa có node lớn nhất bên trái
                            //findreplace1(p->right,p);// tìm khóa có node nhỏ nhất bên phải
                            delete p;
                        }
            }
    }
    else
    {
        return NULL;
    }
}

int main()
{
    tree l;
    createTree(l);
    int x;
    while(true)
    {
        cin >> x;
        if(x == -1) break;
        AddNode(l,x);
    }
    cout<<"NLR ";
    NLR(l);
    cout<<"\nLNR ";
    LNR(l);
    cout <<"\nLRN ";
    LRN(l);
    cout<<"\nNut la: ";
    nutla(l);
    cout<<"\nNut trong: ";
    nuttrong(l,0);
    cout << "\nNut co dung 1 con: ";
    nut1con(l);
    cout << "\nNut co dung 2 con: ";
    nut2con(l);
    cout << "\nTim gia tri: ";
    node *p;
    cin >>x;
    p = find(l,x);
    if(p)
    {
        cout << p->data << " da tim thay! ";
    }
    else
    {
        cout << " khong thay! ";
    }
    cout << "\nXoa node: ";
    cin >> x;
    p = deletenode(l,x);
    if(p)
    {
        cout << " xoa thanh cong!\n";
        cout<< "LRN: ";LRN(l); 
    }
    else
    {
        cout << " khong thay!\n ";
    }
    return 0;
}