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

node *swapNode(List &L, int x, int y)
{
    if(L.pHead == NULL || L.pHead->next == NULL) return NULL;
    node* p = L.pHead;
    node* posx = NULL;
    node* saux = NULL;
    node* sauy = NULL;
    node* posy = NULL;
    int demx = 0;
    int demy = 0;
    while (p != NULL && p->info != x)
    {
        demx++;
        saux = p;
        p = p->next;
    }
    posx = p;
    if(x == y) return posx;
    p = L.pHead;
    while(p != NULL && p->info != y)
    {
        demy++;
        sauy = p;
        p = p->next;
    }
    posy = p;
    p =L.pHead;
    if(posx == NULL || posy == NULL)
        return NULL;
    
    ////////////////////////////////////
    if(demx > demy)
    {
        node *temp1 = posx;
        posx = posy;
        posy = temp1;
        temp1 = saux;
        saux = sauy;
        sauy = temp1;
        temp1 = NULL;
        delete temp1;
    }
    ////////////////////////////////////
    sauy->next = posy->next;
    if(sauy != posx)
    {
        posy->next = posx->next;
        if(saux == NULL)
        {
            L.pHead = posy;
        }
        posx->next = sauy->next;
        sauy->next = posx;
    }
    else
    {
        posy->next = posx;
        if(saux == NULL)
        {
            L.pHead = posy;
        }
    }
    if(saux != NULL)
    {
        saux->next = posy;
    }
    if(demy < demx) return posy;
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
    outputList(L);
    cout<<endl;

    int x, y; cin>>x>>y;
    node *p = swapNode(L,x,y); // Tim 2 node chua x va y, Hoan vi 2 node, thay doi cac moi lien ket giua cac node
    /* Tim 2 node chua x va y,
    Hoan vi 2 node do,
    nghia la: Thay doi moi lien ket giua cac node co lien quan, doi cho cac node, gia tri chua trong cac node khong thay doi
    Ham return node chua x ban dau, luc chua hoan vi*/

    cout<<"Updated List after swapping "<<x<<" and "<<y<<": "<<endl;
    outputList(L);
    cout<<endl;

    /* Kiem tra xem co that su hoan vi 2 node khong
    Neu hoan vi node thi node chua x ban dau cung van chua x, gia tri cua node khong thay doi*/
    if(p) // co doi cho
    {
        cout<<"At the address of "<<x<< ": ";
        cout<<p->info;
    }
    else cout<<"Can not swap";
    return 0;
}
