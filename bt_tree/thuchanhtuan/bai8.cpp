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

typedef node* Tree;

node* getNode(int x)
{
    node* newele = new node;
    if(newele != NULL)
    {
        newele->data = x;
        newele->left = NULL;
        newele->right = NULL;
        newele->prev = NULL;
    }
    return newele;
}

node* Search(Tree T, int b)
{
    if(T == NULL)
        return NULL;

    if(T->data == b)
        return T;

    node* timnode = Search(T->left,b);
    if(timnode != NULL)
        return timnode;
    
    timnode = Search(T->right,b);
    if(timnode)
        return timnode;

    return NULL;
}


void SetLeft(node* p, int c)
{
    node *chen = getNode(c);
    if(p == NULL)
        cout<<"Node khong ton tai\n";
    else if(p->left == NULL )
    {
        p->left = chen;
        chen->prev = p;
    }
    else
    {
        cout << "Da co node con ben trai\n";
    }
    
    
}

void SetRight(node* p, int c)
{
    node *chen = getNode(c);
    if(p == NULL)
        cout<<"Node khong ton tai\n";
    else if(p->right == NULL)
    {
        p->right = chen;
        chen->prev = p;
    }
    else 
    {
        cout << "Da co node con ben phai\n";
    }
}

bool isBST(Tree T)
{
     if (T == NULL)
        return true;

    if (T->left != NULL)
    {
        if (T->left->data >= T->data)
            return false;

        if (!isBST(T->left))
            return false;
    }

    if (T->right != NULL)
    {
        if (T->right->data <= T->data)
            return false;

        if (!isBST(T->right))
            return false;
    }

    return true;
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

int main()
{
	Tree T = NULL;
	int x,b,c; char a;
	cin>>x;	T=getNode(x); // tao nut goc
	while(true)
    {
        cin>>a; // Ky tu cho biet chen vao trai hay phai
        if(a!='L'&& a!='R') break; // Neu khong phai L hoac R thi ket thuc viec tao cay
        cin>>b>>c;
        if(a=='L') SetLeft(Search(T,b),c); // chen c vao ben trai b
        else if (a=='R') SetRight(Search(T,b),c); // chen c vao ben phai b
    }
	cout<<"\nLNR: "; LNR(T); cout<<endl;
    if(isBST(T)) cout<<"\nCay vua tao la cay BST";
    else cout<<"\nCay vua tao khong phai la cay BST";

	return 0;
}
