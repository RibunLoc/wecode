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

struct PROVINCE
{
    int id;
    char tentinh[31];
    int pop;
    float area;
};

struct node
{
    PROVINCE data;
    node *pNext;
    node *pPrev;
};

struct List
{
    node *pHead;
    node *pTail;
};

void Init(List &L)
{
    L.pHead = NULL;
    L.pTail = NULL;
}

node* getnode(List &L, PROVINCE x)
{
    node *newele = new node;
    if(newele != NULL)
    {
        newele->data = x;
        newele->pNext = NULL;
        newele->pPrev = NULL;
    }
    return newele;
}

void addTail(List &L, PROVINCE x)
{
    node *newnode = getnode(L,x);
    if(L.pHead == NULL)
        L.pHead = L.pTail = newnode;
    else
    {
        L.pTail->pNext = newnode;
        newnode->pPrev = L.pTail;
        L.pTail = newnode;
    }
}

PROVINCE inputdata()
{
    PROVINCE data;
    cin >> data.id;
    cin.ignore();
    cin.getline(data.tentinh,31);
    cin >> data.pop;
    cin >> data.area;
    return data;
}

void delenode(List &L , node* &p)
{
    if(p == L.pHead)
    {       
        if (L.pHead->pNext == NULL) 
        {
            node *temp = p;
            p = NULL;
            delete temp;
            Init(L);
        }
        else
        {
            L.pHead = p->pNext;
            L.pHead->pPrev = NULL;
            p->pNext = NULL;
            p = L.pHead;
        }
    }else if(p == L.pTail)
        {
            L.pTail = p->pPrev;
            L.pTail->pNext = NULL;
            p->pPrev = NULL;
            p = NULL;
        }else
        {
            p->pPrev->pNext = p->pNext;
            p->pNext->pPrev = p->pPrev;
            node *temp = p;
            p = p->pNext;
            temp->pNext = NULL;
            temp->pPrev= NULL;
            delete temp;
        }
}

void inputListProvinces(List &L)
{
    int n;
    do
    {
        cin >> n;
    } while (n < 0 || n >= 100);
    for (int i = 0; i < n; i++)
    {
        PROVINCE data;
        data = inputdata();
        addTail(L,data);
    }
}

void outputdata(node *p)
{
    cout << p->data.id<<"\t"<<p->data.tentinh<<"\t"<<p->data.pop<<"\t"<<p->data.area<<"\t"<<endl;
}

void outputListProvinces(List L)
{
     if(L.pHead == NULL)
    {
        cout << "List is empty";
        return;
    }
    node *p = L.pHead;
    while(p != NULL)
    {
        outputdata(p);
        p = p->pNext;
    }
}

void removeList(List &L)
{
    node *p = L.pHead;
   
    while (p != NULL)
    {
        delenode(L,p);
    }
}

int main()
{
    List L;
    Init(L);
    inputListProvinces(L);
    cout<<"List of provinces:"<<endl;
    cout<<"ID\t|Province\t|Population\t|Area"<<endl;
    outputListProvinces(L);

    if(L.pHead)
    {
        cout<<"Delete all:"<<endl;
        removeList(L);
        outputListProvinces(L);
    }
    return 0;
}




