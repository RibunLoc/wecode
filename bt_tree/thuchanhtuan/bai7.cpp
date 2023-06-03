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

node* getNode(int x)
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
        return;
    else if(p->left == NULL )
    {
        p->left = chen;
    }
       
}

void SetRight(node* p, int c)
{
    node *chen = getNode(c);
    if(p == NULL)
        return;
    else if(p->right == NULL)
    {
        p->right = chen;
    }
   
}

void DeleteLeft(node* p)
{
    if(p == NULL)
        cout<<"Node khong ton tai\n";
    else if(p->left == NULL)
    {
        cout << "Khong co node ben trai\n";
    }
    else
    {
        node *Tleft = p->left;
        if(Tleft->left != NULL || Tleft->right != NULL)
        {
            cout << "Khong la node la nen khong xoa duoc\n";
        }
        else
        {
            p->left = NULL;
            delete Tleft;
        }
        
    }
}

void DeleteRight(node* p)
{
    if(p == NULL)
        cout<<"Node khong ton tai\n";
    else if(p->right == NULL)
    {
        cout << "Khong co node ben phai\n";
    }
    else
    {
        node *Tright = p->right;
        if(Tright->left != NULL || Tright->right != NULL)
        {
            cout << "Khong la node la nen khong xoa duoc\n";
        }
        else
        {
            p->right = NULL;
            delete Tright;
        }
        
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

int main()
{
	Tree T = NULL;
	int x,b,c; char a;
	cin>>x;	T=getNode(x); // tao nut goc
	while(true)
    {
        cin>>a; // Ky tu cho biet chen vao trai hay phai
        if(a!='L'&& a!='R') break;
        cin>>b>>c;
        if(a=='L') SetLeft(Search(T,b),c);
        else if (a=='R') SetRight(Search(T,b),c);

    }
	cout<<"LNR: "; LNR(T);
	cout<<"\nDelete some nodes:\n";
	string s;
	while(true)
    {
        cin>>s; // Chuoi cho biet xoa ben trai hay ben phai
        if(s!="DL"&& s!="DR") break;
        cin>>b;
        if(s=="DL") DeleteLeft(Search(T,b));
        else if(s=="DR") DeleteRight(Search(T,b));

    }
    cout<<"\nLNR: "; LNR(T);

	return 0;
}
