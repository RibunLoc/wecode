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
    node* next;
};

struct List
{
    node* head;
    node* tail;
};

node* getnode(int x)
{
    node *newele = new node;
    if(newele != NULL)
    {
        newele->data = x;
        newele->next = NULL;
    }
    return newele;
}
void Init(List &L)
{
    L.head = NULL;
    L.tail = NULL;
}

void addtail(List &L, int x)
{
    node *newnode = getnode(x);
    if(L.head == NULL)
        L.head = L.tail = newnode;
    else
    {
        L.tail->next = newnode;
        L.tail = newnode;
    }
}
void addhead(List &L, int x)
{
    node *newnode = getnode(x);
    if(L.head == NULL)
        L.head = L.tail = newnode;
    else
    {
        newnode->next = L.head;
        L.head = newnode;
    }
}
void deletehead(List &L)
{
    if(L.head == NULL)

    return;
    else
    {
        node* p = L.head;
        L.head = p->next;
        p->next = NULL;
        delete p;
        if(L.head == NULL) L.tail = NULL;
    }
}

void deletetail(List &L)
{
    if(L.head == NULL)
        return;
    else
    {
        node* p = L.head;
        if(L.head == L.tail)
        {
            deletehead(L);
        }
        else
        {
            node *sau = NULL;
            while(p->next != NULL)
            {
                sau = p;
                p = p->next;
            }
            if(sau != NULL)
            {
                L.tail = sau;
                L.tail->next = NULL;
            }
            else
            {
                L.tail = NULL;
                L.head = NULL;
            }
        }
    }
}
void inputList(List &L, int n)
{   
   char x,y;
   int z;
   for (int i = 0; i < n; i++)
   {
     cin >> x; cin >> y;
    cin >> z;
    if(x == '+')
    {
        if(y == 'T')
        {
            addtail(L,z);
        }
        else
        {
            addhead(L,z);
        }
    }
    else
    {
        if(y == 'H')
        {
            deletehead(L);
        }
        else
        {
            deletetail(L);
        }
    }
   }
   
  
}


void outputList(List L)
{
    if(L.head == NULL)
        cout << "List is empty "<<endl;
    else
    {
        node* p = L.head;
        while(p != NULL)
        {
            cout <<p->data << " ";
            p = p->next;
        }
    }
}


int main()
{
    List L; // Khai bao 1 danh sach
    Init(L); // Khoi tao danh sach
    int n; cin >> n;
    inputList(L,n);
    outputList(L);

    return 0;
}
