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
    string info;
    node* next;
};

struct List
{
    node *head;
    node *tail;
};

void Init(List &L)
{
    L.head = L.tail = NULL;
}

node *getnode(string x)
{
    node* newele = new node;
    if(newele != NULL)
    {
        newele->info = x;
        newele->next = NULL;
    }
    return newele;
}


void addtail(List &L, string x)
{
    node *newnode = getnode(x);
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

void inputList(List &L, int n)
{ 
    cin.ignore();
    for(int i = 0; i < n; i++)
    {
       
        string x;
        getline(cin,x);
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
        node *p = L.head;
        while (p != NULL)
        {
            cout << p->info << " ";
            p = p->next;
        }
    }
}

node* findindex(List L, int dem, int i)
{
    if(i > dem)
    {
        string x = "The index is invalid";
        addtail(L,x);
        return L.tail;
    }
    node *p = L.head;
    while (p != NULL && dem != i)
    {
        dem--;
        p = p->next;
    }
    return p;
}

node* findElementFromEnd(List &L, int i)
{
   if(L.head == NULL)
   {
        string x = "List is empty";
        addtail(L,x);
        node *p = L.head;
        return p;
   } 
   else
   {
        int dem = 0;
        node *p = L.head;
        while (p != NULL)
        {
            dem ++;
            p = p->next;
        }
        p = findindex(L,dem,i);
        return p;    
   }
}

int main()
{
    List L;
    Init(L);
    int n; cout<<"Enter a number: "; cin>>n;
    cout<<"\nEnter a sequence of "<<n<<" numbers: ";
    inputList(L,n);
    cout<<"\nThe created Linked List: ";
    outputList(L);

    int i; cout<<"\nEnter a number: "; cin>>i;
    cout<<"\nThe element at index "<<i<<" (from the end of L): ";
    node *p = findElementFromEnd(L,i);
    if(p) cout<<p->info;


    return 0;
}
