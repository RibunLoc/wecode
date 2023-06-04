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
int nodesWithLevel(Tree T, int k, int c);

int main()
{
    Tree T = NULL;
    inputTree(T);
    cout<<"\nNLR: "; NLR(T);
    int k; cout<<"\nEnter k: "; cin >>k;
    cout<<nodesWithLevel(T,k,0); //neu tham so thu 3 khong can dung thi trong ham khong can xu ly

    return 0;
}
//###INSERT CODE HERE - // in các nút có mức là k trong cây, in theo thứ tự từ PHẢI QUA TRÁI
Node* getNode(int x)
{
    Node* newele = new Node;
    if(newele != NULL)
    {
        newele->info = x;
        newele->pLeft = NULL;
        newele->pRight = NULL;
    }
    return newele;
}

void insertNode(Tree &T, int x)
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
    int n;
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

void muc_cay(Tree T, int k, int c, int &d)
{
    if(T == NULL)
        return;

    if(k == 0)
    {
        ++d;
        cout << T->info << " ";
        return;
    }

    muc_cay(T->pRight,k - 1, c,d);
    muc_cay(T->pLeft,k - 1,c,d);
    
}

int nodesWithLevel(Tree T, int k, int c)
{
    int count = 0;
    cout << "\nList of nodes with level "<< k <<" (R->L): "; muc_cay(T,k,c,count);
    cout << "\nNumber of nodes with level "<<k<<": ";
    return count;
 
}
