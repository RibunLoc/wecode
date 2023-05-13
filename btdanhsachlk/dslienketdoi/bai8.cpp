#include <iostream>
#include <queue>

using namespace std;

struct node
{
    int data;
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

node* getnode(int x)
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

void addtail(DList &L, int x)
{
    node* newnode = getnode(x);
    if(L.pHead == NULL)
        L.pHead = L.pTail = newnode;
    else
    {
        L.pTail->pNext = newnode;
        newnode->pPrev = L.pTail;
        L.pTail = newnode;
    }
}

void telenode(DList &L, node* &p)
{
    if(p == L.pHead)
    {
        p = NULL;delete p;
        return;    
    }
    else if(p == L.pTail) // đưa lên đầu
        {
            node* cop = p;
            L.pTail = p->pPrev;
            L.pTail->pNext = NULL;
            p->pPrev = NULL;
            p = NULL;
            delete p;
            cop->pNext = L.pHead;
            L.pHead->pPrev = cop;
            L.pHead = cop;
            
        }
        else
        {
            node* cop = p;
           p->pNext->pPrev = p->pPrev;
           p->pPrev->pNext = p->pNext;
           p->pNext = NULL;
           p->pPrev = NULL;
           p = NULL;
           delete p;
           cop->pNext = L.pHead;
           L.pHead->pPrev = cop;
           L.pHead = cop;
        }
}


void tellperson(DList &L ,int m, node* *array)
{
    int per;

    for (int i = 1; i <= m; i++)
    {
        cin >> per;
        node *p = array[per];

        if(p)
        {
            telenode(L,p);
        }
        else
        {
            delete p;// không tìm thấy
        }
        cout << L.pTail->data << " ";
    }
    
}

void inputList(DList &L, node* *array, int n)
{

    for (int i = 1; i <= n; i++)
    {
        addtail(L,i);
        array[i] = L.pTail;
    }
    
}

int main()
{
    DList L;
    init(L);
    int n,m;
    do
    {
        cin >> n;
        cin >> m;
    } while (m < 0 || n < 0);
    node* *array = new node*[n+1];
    inputList(L,array,n);
    tellperson(L,m,array);
    
    delete[] array;
    return 0;
}