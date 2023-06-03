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
        cout<<"Node khong ton tai\n";
    else if(p->left == NULL )
    {
        p->left = chen;
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
    }
    else 
    {
        cout << "Da co node con ben phai\n";
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
        if(a!='L'&& a!='R') break; // Neu khong phai L hoac R thi ket thuc viec tao cay
        cin>>b>>c;
        if(a=='L') SetLeft(Search(T,b),c); // chen c vao ben trai b
        else if (a=='R') SetRight(Search(T,b),c); // chen c vao ben phai b
    }
	cout<<"\nLNR: "; LNR(T); cout<<endl;

	return 0;
}
