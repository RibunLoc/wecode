/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
[
###End banned keyword*/

#include <iostream>
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
void init(List &L)
{
    L.pHead = L.pTail = NULL;
}
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

void swapdata(node* &a, node* &b)
{
    int temp = a->info;
    a->info = b->info;
    b->info = temp;
}

void MySort(List &L)
{  
    if(L.pHead == NULL || L.pHead->next == NULL) return;

    node *truoc = L.pHead;
    node *sau = L.pHead->next;
    while(truoc != NULL)
    {
        int data = truoc->info;
        node* min = truoc;
        while (sau != NULL)
        {
            if(sau->info < data)
            {
                data = sau->info;
                min = sau;
            }
            sau = sau->next;
        }
        if(data != truoc->info)
            swapdata(truoc,min);
        truoc = truoc->next;
        if(truoc != NULL)
            sau = truoc;
        else
            sau = NULL;

    }
}

int MySearch(List &L, int x)
{
    if(L.pHead == NULL) return - 1;
    int pos = -1;
    node *p = L.pHead;
    while (p != NULL)
    {
        pos++;
        if(p->info == x)
        return pos;
        p = p->next;
    }
    return -1;
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
    int n; cin>>n;
    List L;init (L);
    inputList(L,n);
    MySort(L);
    cout<<"Sorted List: ";
    outputList(L);// liet ke cac phan tu cach nhau boi 1 khoang cach

    cout<< "\nFind an element: ";
    int x; cin>>x;
    cout<<x<<endl;
    int result = MySearch(L,x);
    if (result ==-1) cout<<x<<" is not found";
    else cout<<x<<" is found at the position " << result;

	return 0;
}

