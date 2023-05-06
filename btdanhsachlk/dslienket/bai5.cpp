/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include <iostream>
#include <cstring>
#include <string>
using namespace std;

//###INSERT CODE HERE -

struct node
{
    int data;
    node *next;
};

struct List
{
    node* pHead;
    node* pTail;
};

node* getnode(int x)
{
    node* newele = new node;
    if(newele != NULL)
    {
        newele->data = x;
        newele->next = NULL;
    }
    return newele;
}

void addtail(List &L, int x)
{
    node *newnode = getnode(x);
    if(L.pHead == NULL)
    {
        L.pHead = L.pTail = newnode;
    }
    else
    {
        L.pTail->next = newnode;
        L.pTail = newnode;
    }
}


void moveLastToFront(List &L)
{
    if(L.pHead == NULL || L.pHead->next == NULL)
    {
        return;
    }
    else
    {
        node *p = L.pHead;
        node *sau = NULL;
        while (p->next != NULL)
        {
            sau = p;
            p = p->next;
        }
        L.pTail = sau;
        p->next = L.pHead;
        L.pHead = p;
        sau->next = NULL;
        
    }

}


void inputList(List &L, int n)
{
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        addtail(L,x);
    }
    
}


void outputList(List L)
{
    node *p = L.pHead;
    if(L.pHead == NULL)
    {
        cout << "List is empty";
    }
    else
    {
        while (p != NULL)
        {
            cout << p->data << " ";
            p = p->next;
        }
    }
    delete p;
}





int main()
{
    List L;
    L.pHead=L.pTail=NULL;
    int n; cin>>n;
    inputList(L,n);
    cout<<"Created List: "<<endl;
    outputList(L);
    cout<<endl;

    moveLastToFront(L); //di chuyen node cuoi ve dau danh sach
    cout<<"Updated List after moving the last element to front of L: "<<endl;
    outputList(L);
    return 0;
}
