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
    int info;
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
        newele->info = x;
        newele->next = NULL;
    }
    return newele;
}


void addtail(List &L, int x)
{   
    node* newnode = getnode(x);
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
    if(L.pHead == NULL)
    {
        cout << "List is empty";
    }
    else
    {
        node *p = L.pHead;
        while (p != NULL)
        {
            cout << p->info << " ";
            p = p->next;
        }
        delete p;
    } 
}

node* findMiddle(List L)
{
    if(L.pHead == NULL)
    {
        return NULL;
    }
    else
    {
        int dem = 0;
        node *p = L.pHead;
        while (p != NULL)
        {
            dem++;
            p = p->next;
        }
        int n;
        if(dem % 2 == 0)
        {
            n = dem / 2 + 1;
            p = L.pHead;
            int i = 1;
            while(p != NULL && i != n)
            {
                p = p->next;
                i++;
            }
            if(p == NULL)
            return NULL;
            return p;
        }
        else
        {
            n = (dem + 1) / 2;
            p = L.pHead;
            int i = 1;
            while(p != NULL && i != n)
            {
                p = p->next;
                i++;
            }
            if(p == NULL)
                return NULL;
            return p;
        }
        
    }
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

    node *p=findMiddle(L); //Neu so phan tu chan thi co 2 phan tu chinh giua, chi xuat phan tu chinh giua thu 2
    if(p)cout<<"The middle element is "<<p->info;

    return 0;
}
