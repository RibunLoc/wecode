/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include <iostream>
using namespace std;

struct Node
{
    int info;
    Node *pLeft;
    Node *pRight;
};
typedef struct Node* Tree;

Node *getNode(int x);
void insertNode(Tree & T, int x);
void inputTree(Tree &T);
void NLR(Tree T);
bool isSquare (int n);
void SearchStandFor(Node* &p, Node* &q); //Chon node phai nhat tren nhanh con ben trai
void deleteSquareNumbers(Tree &T);

int main()
{
    Tree T = NULL;
    inputTree(T);
    cout<<"\nNLR: "; NLR(T);
    cout<<"\nDelete all square numbers:";
    deleteSquareNumbers(T);
    cout<<"\nNLR: "; NLR(T);

    return 0;
}
//###INSERT CODE HERE -
Node *getNode(int x)
{
    Node *newele = new Node;
    if(newele != NULL)
    {
       newele->info = x;
       newele->pLeft = NULL;
       newele->pRight = NULL;
    }
    return newele;
}

void insertNode(Tree & T, int x)
{
    if(T)
    {
        if(T->info > x)
            insertNode(T->pLeft,x);
        else if(T->info < x)
        {
            insertNode(T->pRight,x);
        }
        else
            return;
    }
    else
    {
        T = getNode(x);
    }
}

void inputTree(Tree &T)
{
    int n ;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        insertNode(T,x);
    }
    
}

void NLR(Tree T)
{
    if(T)
    {
        cout << T->info << " ";
        NLR(T->pLeft);
        NLR(T->pRight);
    }
}

bool isSquare (int n)
{
    if(n == 1) return true;
    for (int i = 1; i <= n/2; i++)
    {
        if(i*i == n)
            return true;
    }
    return false;
}

void SearchStandFor(Node* &p, Node* &q)
{
    if(p->pRight != NULL)
        SearchStandFor(p->pRight,q);
    else
    {
        q->info = p->info;
        p = p->pLeft;
    }
}

void deleteSquareNumbers(Tree &T)
{
    if(T)
    {
        if(isSquare(T->info))
        {
            if(T->pLeft == NULL && T->pRight == NULL)
            {
                T = NULL;
            }
            else if(T->pLeft != NULL  && T->pRight == NULL)
            {
                T = T->pLeft;
            }
            else if(T->pLeft == NULL && T->pRight != NULL)
            {
                T = T->pRight; 
            }
            else
            {
                SearchStandFor(T->pLeft,T);
 
            }
            deleteSquareNumbers(T);
        }
        else
        {
            deleteSquareNumbers(T->pLeft);
            deleteSquareNumbers(T->pRight);
        }
        
    }
}