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
    node* prev;
};
const int Max_size = 100;
class stack
{
public:
    node* data[Max_size];
    int top;
public:
    stack()
    {
        top = -1;
    }

    bool empty()
    {
        return (top == -1);
    }

    bool isFull()
    {
        return (top == Max_size - 1);
    }

    void push(node* val)
    {
        if(!isFull())
        {
            data[++top] = val;
        }
    }
   

    void pop()
    {
        if(!empty())
        {
            top--;
        }
    }
};


typedef node* Tree;

node* getnode(int x)
{
    node* newele = new node();
    if(newele != NULL)
    {
        newele->data = x;
        newele->left = NULL;
        newele->right = NULL;
        newele->prev = NULL;
    }
    return newele;
}
bool tieptuc = true;
void addTree(Tree &root, int x,node* past)
{
    if(root)
    {
        if(root->data > x)
        {
            past = root;
            addTree(root->left,x,past);
        }
        else if(root->data < x)
        {
            past = root;
            addTree(root->right,x,past);
        }
        else
        {
            cout<<"Bi trung gia tri, ket thuc qua trinh tao cay"<<endl;
            tieptuc = false;
            return;
        }
    }
    else
    {
        root = getnode(x);
        root->prev = past;
    }
}


void inputTree(Tree &root)
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {

        if(!tieptuc)
            break;
        node* past = NULL;;
        int x;
        cin >> x;
        addTree(root,x,past);
    }
    
}
bool cay_rong = true;
void NLR(Tree root)
{
    if(root)
    {
        stack xep;
        xep.push(root);
    while (!xep.empty())
    {
        node* p = xep.data[xep.top];
        xep.pop();

        cout << p->data << " ";
        if(p->right != NULL)
            xep.push(p->right);
        if(p->left != NULL)
            xep.push(p->left);
    }
    }
    if(root == NULL && tieptuc)
    {
        cout<< "\nKhong the xoay vi cay rong";
    }
    else if(root->left == NULL && tieptuc)
    {
        cout<< "\nKhong the xoay phai vi khong co nut con ben trai";
    } 
    

        tieptuc = false;

}

node* rotateRight(Tree root)
{
    if(root)
    {
        if(root->left != NULL)
        {     
            node* p = root;
            root = p->left;
            node* q = root->right;
            root->right = p;
            p->left = q;
        }
    }
    return root;
}

int main()
{
	Tree T = NULL;
	inputTree(T);
	cout<<"NLR: "; NLR(T);
	T=rotateRight(T);
	cout<<"\nUpdated Tree: \n";
	cout<<"NLR: "; NLR(T);
	return 0;
}



