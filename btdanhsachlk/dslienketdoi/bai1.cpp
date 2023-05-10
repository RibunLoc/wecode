
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
///
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
    while(p != NULL && p->info != x)
    {
        p = p->pNext;
    }
    if(p == NULL) 
        cout << "\nCan't find the value "<<x;
    else
    {
        if(p == L.pTail)
            addTail(L,y);
        else
        {
            DNode *newnode = getnode(y);
            newnode->pNext = p->pNext;
            p->pNext->pPrev = newnode;
            p->pNext = newnode;
            newnode->pPrev = p;
        }
        p = NULL;
    }
    delete p;
}

void addBefore(DList &L, int x, int y)
{
    DNode *p = L.pHead;
    while(p != NULL && p->info != x)
    {
        p = p->pNext;
    }
    if(p == NULL)
        cout << "\nCan't find the value "<<x;
    else 
    {
            if(p == L.pHead)
                addHead(L,y);
            else
            {
                DNode *newnode = getnode(y);
                newnode->pPrev = p->pPrev;
                p->pPrev->pNext = newnode;
                newnode->pNext = p;
                p->pPrev = newnode;
            }
            p = NULL;
    }
    delete p;
}

void addBeforeMulti(DList &L, int x, int y)
{
    
    DNode *find = L.pHead;
    while(find != NULL && find->info != x)
    {
        find = find->pNext;
    }
    
    if(find == NULL)
        cout << "\nCan't find the value "<<x;
    else
    {
       DNode *p = find;
       find = NULL;
       while(p != NULL)
       {
            if(p->info == x && p == L.pHead)
            {
                addHead(L,y);
            }
            else if(p->info == x)
                {
                    DNode *newnode = getnode(y);
                    newnode->pPrev = p->pPrev;
                    p->pPrev->pNext = newnode;
                    newnode->pNext = p;
                    p->pPrev = newnode;
                }
            p = p->pNext;
       }
        delete p;
    }
    delete find;
}


void addAfterMulti(DList &L, int x, int y)
{
    DNode *find = L.pHead;
    while(find != NULL && find->info != x)
    {
        find = find->pNext;
    }

    if(find == NULL)
        cout << "\nCan't find the value "<<x;
    else
    {
        DNode *p = find;
        find = NULL;
        while (p != NULL)
        {
            if(p->info == x)
            {
                if(p == L.pTail)
                {
                    addTail(L,y);
                    p = p->pNext;
                }
                else
                {
                    DNode *newnode = getnode(y);
                    newnode->pNext = p->pNext;
                    p->pNext->pPrev = newnode;
                    p->pNext = newnode;
                    newnode->pPrev = p;
                    p = p->pNext;
                }
            }
            p = p->pNext;
        }
        delete p;
    }
    delete find;
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
        cout << "The list is empty";
    else
    {
        while(p != NULL)
        {
            cout << p->info << " ";
            p = p->pNext;
        }

    }
    delete p;
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
