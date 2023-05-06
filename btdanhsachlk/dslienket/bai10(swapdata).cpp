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
    node *pHead;
    node *pTail;
};

node* getnode(int x)
{
    node *newele = new node;
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

node *swapData(List &L, int x, int y)
{
    if(L.pHead == NULL || L.pHead->next == NULL) return NULL;
    node* p = L.pHead;
    node* posx = NULL;
    node* posy = NULL;
    bool ktr_x = true;
    bool ktr_y = true;
    while (p != NULL)
    {
        if(p->info == x && ktr_x)
        {
            posx = p;
            ktr_x = false;
        }
        if(p->info == y && ktr_y)
        {
            posy = p;
            ktr_y = false;
        }
        if(!ktr_x && !ktr_y)
        {    
            p = L.pHead;
            break;
        }
        p = p->next;
    }
    if(posx == NULL || posy == NULL)
        return NULL;
    swap(posx->info,posy->info);
    return posx;

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
    }
}


int main()
{
    List L;
    L.pHead=L.pTail=NULL;
    int n; cin>>n;
    inputList(L,n);
    cout<<"Created List: "<<endl;
    outputList(L); // Neu ds rong thi xuat "List is empty"
    cout<<endl;

    int x, y; cin>>x>>y;
    node *p = swapData(L,x,y);
    /* Tim 2 node chua x va y,
    Hoan vi gia tri cua 2 node do,
    nghia la: Lien ket giua cac node khong thay doi, node ban dau chua x se doi lai la chua y
    Ham return node chua x ban dau, luc chua hoan vi*/

    cout<<"Updated List after swapping "<<x<<" and "<<y<<": "<<endl;
    outputList(L);
    cout<<endl;

    /* Kiem tra xem co that su hoan vi info cua 2 node khong
    Neu hoan vi info thi node chua x ban dau se doi lai chua y*/

    if(p) // co hoan vi
    {
        cout<<"At the address of "<<x<< ": ";
        cout<<p->info;
    }
    else cout<<"Can not swap";
    return 0;
}
