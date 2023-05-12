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

struct DList
{
    node *pHead;
    node *pTail;
};

void init(DList &L)
{
    L.pHead = NULL;
    L.pTail = NULL;
}

node* getnode(DList &L, PROVINCE x)
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

void addTail(DList &L, PROVINCE x)
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

void delenode(DList &L , node *p)
{
    if(p == L.pHead)
    {       
        if (L.pHead->pNext == NULL) 
        {
            delete p;
            init(L);
        }
        else
        {
            L.pHead = p->pNext;
            L.pHead->pPrev = NULL;
            p->pNext = NULL;
            delete p;
        }
    }else if(p == L.pTail)
        {
            L.pTail = p->pPrev;
            L.pTail->pNext = NULL;
            p->pPrev = NULL;
            delete p;
        }else
        {
            p->pPrev->pNext = p->pNext;
            p->pNext->pPrev = p->pPrev;
            p->pNext = NULL;
            p->pPrev= NULL;
            node *temp = p;
            delete temp;
        }
}

bool ktrname(node *p , char name[31])
{
    for (int i = 0; i <= strlen(p->data.tentinh); i++)
    {
        if(p->data.tentinh[i] != name[i])
            return false;    
    }
    return true;
    
}

node* deleteinfo(DList &L)
{
    char name[31];
    cout << "Enter the name of the province you want to delete: ";
    cin.ignore();
    cin.getline(name,31);
    node *p = L.pHead;
    while (p != NULL)
    {
        if(ktrname(p,name))
            break;
        p = p->pNext;
    }
    if(p)
    {
        delenode(L,p);
        return p;
    }
        return NULL;
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

void inputList(DList &L)
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

void outputList(DList L)
{
    cout << "ID\t"<<"|Province\t"<<"|Population\t"<<"|Area\t"<<endl;
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

int main()
{
    DList L;
    init(L);
    inputList(L);
    cout << "List of provinces:"<< endl;
    outputList(L);
    if(L.pHead == NULL)
        return 0;
    node* p = deleteinfo(L);
    if(p == NULL)
    {
        delete p;
        cout << "Not found";
    }
    else
    {
        cout << "Updated List:"<<endl;
        outputList(L);
        p = NULL;
        delete p;
    }


    return 0;
}




