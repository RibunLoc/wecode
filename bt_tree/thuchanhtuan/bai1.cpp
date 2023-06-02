/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include <iostream>
using namespace std;

//###INSERT CODE HERE -
bool tieptuc = true;
struct node
{
    int data;
    node* left;
    node* right;
};

typedef node* Tree;

node* getnode(int x)
{
    node* newele = new node;
    if(newele != NULL)
    {
        newele->data = x;
        newele->left = NULL;
        newele->right = NULL;
    }
    return newele;
}

void addTree(Tree &root, int x)
{
    if(root)
    {
        if(root->data > x)
            addTree(root->left,x);
        else if(root->data < x)
        {
            addTree(root->right,x);
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
        int x;
        cin >> x;
        addTree(root,x);
        
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

int main()
{
	Tree T = NULL;
	inputTree(T); //Khi bi trung gia tri thi ket thuc qua trinh tao cay, khong nhap tiep nua
	cout<<"NLR: "; NLR(T);
	return 0;
}



