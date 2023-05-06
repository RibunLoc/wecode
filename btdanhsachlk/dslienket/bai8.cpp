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
    node *head;
    node *tail;
};
void Init(List &L)
{
    L.head = NULL;
    L.tail = NULL;
}

node *getnode(int x)
{
    node* newnode = new node;
    if(newnode != NULL)
    {
        newnode->data = x;
        newnode->next = NULL;
    }
    return newnode;
}

void addtail(List &L, int x)
{
    node* newnode = getnode(x);
    if(L.head == NULL)
    {
        L.head = L.tail = newnode;
    }
    else
    {
        L.tail->next = newnode;
        L.tail = newnode;
    }
}


void concate(List &L1, List &L2)
{
    if(L2.head == NULL)
        return;
    if(L1.head == NULL)
    {
        L1.head = L2.head;
        L1.tail = L2.tail;
    }
    else
    {
        L1.tail->next = L2.head;
       L1.tail = L2.tail;
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
    if(L.head == NULL)
    {
        cout << "List is empty";
    }
    else
    {
        node* p = L.head;
        while (p != NULL)
        {
            cout << p->data << " ";
            p = p->next;
        }
        delete p;
    }
}

int main()
{
    List L1, L2;
    Init(L1);Init(L2);

    int n; cin>>n;
    inputList(L1,n);
    cout<<"Created 1st List: "<<endl;
    outputList(L1);
    cout<<endl;

    cin>>n;
    inputList(L2,n);
    cout<<"Created 2nd List: "<<endl;
    outputList(L2);
    cout<<endl;

    concate(L1,L2); // Noi L2 vao L1
    cout<<"Updated L1: "<<endl;
    outputList(L1);

    return 0;
}
