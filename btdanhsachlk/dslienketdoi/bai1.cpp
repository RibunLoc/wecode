
#include  <iostream>
using namespace std;

struct DNode
{
	int info;
	DNode *pNext, *pPrev;
};

struct DList
{
	DNode *pHead, *pTail;
};

void init(DList &L)
{
    L.pHead = NULL;
    L.pTail = NULL;
}

DNode *getnode(int x)
{
    DNode *newele = new DNode;
    if(newele != NULL)
    {
        newele->info = x;
        newele->pNext = NULL;
        newele->pPrev = NULL;
    }
    return newele;
}

void addTail(DList &L, int x)
{
    DNode *newnode = getnode(x);
    if(L.pHead == NULL)
    {
        L.pHead = L.pTail = newnode;
    }
    else
    {
        L.pTail->pNext = newnode;
        newnode->pPrev = L.pTail;
        L.pTail = newnode;
    }

}

void addHead(DList &L, int x)
{
    DNode *newnode = getnode(x);
    if (newnode == NULL) return;
    if(L.pHead == NULL)
    {
        L.pHead = L.pTail = newnode;
    }
    else
    {
        L.pHead->pPrev = newnode;
        newnode->pNext = L.pHead;
        L.pHead = newnode;
    }

}
void addAfter(DList &L, int x, int y)
{
    DNode *p = L.pHead;
    bool ktr = false;
    while (p != NULL)   
    {
        if(p->info == x && p->pNext != NULL)
        {
            ktr = true;
            DNode *newnode = getnode(y);
            if (newnode == NULL) return;
            newnode->pNext = p->pNext;
            p->pNext->pPrev = newnode;
            p->pNext = newnode;
            newnode->pPrev = p;
            p = p->pNext;
            break;
        }
        else if(p->info == x && p->pNext == NULL)
        {
            ktr = true;
            DNode *newnode = getnode(y);
            if (newnode == NULL) return;
            addTail(L,y);
            p = p->pNext;
            break;
        }
        p = p->pNext;
    }
    p = NULL;
    delete p;
    if(!ktr)
        cout << "Can't find the value "<<x;
}

void addBefore(DList &L, int x, int y)
{
    DNode *p = L.pHead;
    bool ktr = false;
    while(p != NULL)
    {
        if(p->info == x && p == L.pHead)
        {
            ktr = true;
            addHead(L,y);
        }else if(p->info == x && p != L.pHead)
                {
                    ktr = true;
                    DNode *newnode = getnode(y);
                    if (newnode == NULL) return;
                    newnode->pPrev = p->pPrev;
                    p->pPrev->pNext = newnode;
                    p->pPrev = newnode;
                    newnode->pNext = p;
                }
        p = p->pNext;
    }
    delete p;
    if(!ktr)
        cout << "\nCan't find the value "<<x;
}

void addBeforeMulti(DList &L, int x, int y)
{
    DNode *p = L.pTail;
    bool ktr = false;
    while(p != NULL)
    {
        if(p->info == x && p->pPrev == NULL)
        {
            ktr = true;
            DNode *newnode = getnode(y);
            if (newnode == NULL) return;
            addHead(L, y);
            p = p->pPrev;
        }else if(p->info == x && p->pPrev != NULL)
        {
            ktr = true;
            DNode *newnode = getnode(y);
            if (newnode == NULL) return;
            newnode->pPrev = p->pPrev;
            p->pPrev->pNext = newnode;
            p->pPrev = newnode;
            newnode->pNext = p;
            p = p->pPrev;
        }
        p = p->pPrev;
    }
    delete p;
    if(!ktr)
        cout << "\nCan't find the value "<<x;
}


void addAfterMulti(DList &L, int x, int y)
{
    DNode *p = L.pHead;
    bool ktr = false;
    while (p != NULL)
    {
        if(p->info == x && p->pNext != NULL)
        {
            ktr = true;
            DNode *newnode = getnode(y);
            if (newnode == NULL) return;
            newnode->pNext = p->pNext;
            p->pNext->pPrev = newnode;
            p->pNext = newnode;
            newnode->pPrev = p;
            p = p->pNext;
        }
        else if(p->info == x && p->pNext == NULL)
        {
            ktr = true;
            DNode *newnode = getnode(y);
            addTail(L,y);
            p = p->pNext;
        }
        p = p->pNext;
    }
    delete p;
    if(!ktr)
        cout << "\nCan't find the value "<<x;
}

void createList(DList &L)
{
    int x;
    do
    {
        cin >> x;
        if(x != -1)
            addTail(L,x);
    } while (x != -1);
    
}
void printList(DList L)
{
    DNode *p = L.pHead;
    if(L.pHead == NULL)
        cout << "\nThe list is empty";
    else
    {
        while(p != NULL)
        {
            cout << p->info << " ";
            p = p->pNext;
        }
    }
}

int main()
{
	DList L;
	init(L);
	int x,y,choice;

	cout<<"MENU:";
    cout<<"\n1. Create a DList";
    cout<<"\n2. Print the DList";
    cout<<"\n3. Insert a value at the front";
    cout<<"\n4. Insert a value at the end";
    cout<<"\n5. Insert a value after a given value (only for the first value found)";
    cout<<"\n6. Insert a value before a given value (only for the first value found)";
    cout<<"\n7. Insert a value after a given value (for all the same values)";
    cout<<"\n8. Insert a value before a given value (for all the same values)";
    cout<<"\n20. Exit"<<endl;

	while(true)
    {
        cout<<"\n\t\tPLEASE SELECT YOUR CHOICE: ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            cout<<"\nEnter your positive integers until you enter -1 to finish: ";
            createList(L);
            break;
        case 2:
            cout<<"\nYour current DList: ";
            printList(L);
            break;
        case 3:
            cout<<"\nEnter a number: ";
            cin>>x;
            addHead(L,x);
            break;
        case 4:
            cout<<"\nEnter a number: ";
            cin>>x;
            addTail(L,x);
            break;
        case 5:
            cout<<"\nEnter two numbers: ";
            cin>>x>>y;
            addAfter(L,x,y);
            break;
        case 6:
            cout<<"\nEnter two numbers: ";
            cin>>x>>y;
            addBefore(L,x,y);
            break;
        case 7:
            cout<<"\nEnter two numbers: ";
            cin>>x>>y;
            addAfterMulti(L,x,y);
            break;
        case 8:
            cout<<"\nEnter two numbers: ";
            cin>>x>>y;
            addBeforeMulti(L,x,y);
            break;
        case 20:
            cout<<"\nGOOD BYE";
            return 0;

        }
    }

	return 0;
}
