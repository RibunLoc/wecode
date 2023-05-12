/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

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

//###INSERT CODE HERE -

void init(DList &L)
{
    L.pHead = NULL;
    L.pTail = NULL;
}

DNode *getnode(int x)
{
    DNode *newele = new DNode;
    if (newele != NULL)
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
    if (L.pHead == NULL)
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
    if (newnode == NULL)
        return;
    if (L.pHead == NULL)
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
    while (p != NULL && p->info != x)
    {
        p = p->pNext;
    }
    if (p == NULL)
        cout << "\nCan't find the value " << x;
    else
    {
        if (p == L.pTail)
            addTail(L, y);
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
    while (p != NULL && p->info != x)
    {
        p = p->pNext;
    }
    if (p == NULL)
        cout << "\nCan't find the value " << x;
    else
    {
        if (p == L.pHead)
            addHead(L, y);
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
    while (find != NULL && find->info != x)
    {
        find = find->pNext;
    }

    if (find == NULL)
        cout << "\nCan't find the value " << x;
    else
    {
        DNode *p = find;
        find = NULL;
        while (p != NULL)
        {
            if (p->info == x && p == L.pHead)
            {
                addHead(L, y);
            }
            else
            {
                if (p->info == x)
                {
                    DNode *newnode = getnode(y);
                    newnode->pPrev = p->pPrev;
                    p->pPrev->pNext = newnode;
                    newnode->pNext = p;
                    p->pPrev = newnode;
                }
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
    while (find != NULL && find->info != x)
    {
        find = find->pNext;
    }

    if (find == NULL)
        cout << "\nCan't find the value " << x;
    else
    {
        DNode *p = find;
        find = NULL;
        while (p != NULL)
        {
            if (p->info == x)
            {
                if (p == L.pTail)
                {
                    addTail(L, y); // có thể là bug ở đây??
                    return;
                }
                else
                {
                    DNode *newnode = getnode(y);
                    newnode->pNext = p->pNext;
                    newnode->pPrev = p;
                    p->pNext->pPrev = newnode;
                    p->pNext = newnode;

                    p = p->pNext;
                }
            }
            p = p->pNext;
        }
        delete p;
    }
    delete find;
}

void removeHead(DList &L)
{
    if (L.pHead == NULL)
    {
        cout << "\nList is empty. Can't delete";
        return;
    }
    cout << "\nDo you want to delete the first element?(y/n): ";
    char y;
    cin >> y;
    if (y == 'y' || y == 'Y')
    {
        if (L.pHead->pNext == NULL)
        {
            L.pHead = NULL;
            L.pTail = NULL;
            cout << "\nThe list becomes empty";
        }
        else
        {
            DNode *p = L.pHead;
            L.pHead = L.pHead->pNext;
            L.pHead->pPrev = NULL;
            p->pNext = NULL;
            delete p;
        }
    }
    else
        return;
}

void removeTail(DList &L)
{
    if (L.pHead == NULL)
    {
        cout << "\nList is empty. Can't delete";
        return;
    }
    cout << "\nDo you want to delete the last element?(y/n): ";
    char y;
    cin >> y;
    if (y == 'y' || y == 'Y')
    {
        if (L.pHead->pNext == NULL)
        {
            L.pHead = NULL;
            L.pTail = NULL;
            cout << "\nThe list becomes empty";
        }
        else
        {
            DNode *p = L.pTail;
            L.pTail = L.pTail->pPrev;
            L.pTail->pNext = NULL;
            p->pPrev = NULL;
            delete p;
        }
    }
    else
        return;
}

void removeNode(DList &L, int x)
{
    if (L.pHead == NULL)
    {
        cout << "\nList is empty. Can't delete";
        return;
    }
    DNode *p = L.pHead;
    while (p != NULL && p->info != x)
    {
        p = p->pNext;
    }
    if (p == NULL)
    {
        cout << "\nCan't find the value " << x;
        delete p;
    }
    else
    {
        char y;
        cout << "\nDo you want to delete " << x << " ?(y/n): ";
        cin >> y;
        if (y == 'y' || y == 'Y')
        {
            if (p == L.pHead && L.pHead->pNext == NULL)
            {
                delete p;
                init(L);
                cout << "\nThe list becomes empty";
            }
            else if (p == L.pTail)
            {
                L.pTail = L.pTail->pPrev;
                L.pTail->pNext = NULL;
                p->pPrev = NULL;
                delete p;
            }
            else if (p == L.pHead)
            {
                L.pHead = L.pHead->pNext;
                p->pNext = NULL;
                L.pHead->pPrev = NULL;
                delete p;
            }
            else
            {
                DNode *sau = p->pPrev;
                sau->pNext = p->pNext;
                p->pNext->pPrev = sau;
                p->pNext = NULL;
                p->pPrev = NULL;
                sau = NULL;
                delete sau;
                delete p; // dọn newnode mà đã gắn
            }
        }
        else
        {
            p = NULL;
            delete p;
        }
    }
}

void removeMultiNodeS(DList &L, int x)
{
    if (L.pHead == NULL)
    {
        cout << "\nList is empty. Can't delete";
        return;
    }
    DNode *p = L.pHead;
    while (p != NULL && p->info != x)
    {
        p = p->pNext;
    }
    if (p == NULL)
    {
        cout << "\nCan't find the value " << x;
        delete p;
    }
    else
    {
        char y;
        cout << "\nDo you want to delete " << x << "s ?(y/n): ";
        cin >> y;
        if (y == 'y' || y == 'Y')
        {
            while (p != NULL)
            {
                if (p->info == x)
                {
                    if (p == L.pHead && L.pHead->pNext == NULL)
                    {
                        delete p;
                        L.pHead = NULL;
                        L.pTail = NULL;
                        cout << "\nThe list becomes empty";
                        return;
                    }
                    else if (p == L.pHead)
                    {
                        L.pHead = p->pNext;
                        L.pHead->pPrev = NULL;
                        p->pNext = NULL;
                        DNode *dele = p;
                        p = L.pHead;
                        delete dele;
                    }
                    else if (p == L.pTail)
                    {
                        L.pTail = p->pPrev;
                        L.pTail->pNext = NULL;
                        p->pPrev = NULL;
                        delete p;
                        return;
                    }
                    else
                    {
                        DNode *sau = p->pPrev;
                        sau->pNext = p->pNext;
                        p->pNext->pPrev = sau;
                        p->pNext = NULL;
                        p->pPrev = NULL;
                        DNode *dele = p;
                        p = sau->pNext;
                        sau = NULL;
                        delete sau;
                        delete dele;
                    }
                }
                else
                {
                    p = p->pNext;
                }
            }
        }
        else
        {
            p = NULL;
            delete p;
        }
    }
}

/////////////////
void removeAfter(DList &L, int x)
{
    DNode *p = L.pHead;
    while (p != NULL && p ->info != x)
    {
        p = p->pNext;
    }
    if(p == NULL)
    {
        cout << "\nCan't find the value "<<x;
        delete p;
    }
    else
    {
        if(p == L.pTail)
            {
                cout<<endl<<x<<" is the last element. Can't delete the element after it";
                p = NULL;delete p;
                return;
            }
        cout<<"\nDo you want to delete the element after "<<x<<" ?(y/n): ";
        char y;
        cin >> y;
        if(y == 'y' || y == 'Y')
        {
                DNode *truoc = p->pNext;
                if(truoc->pNext == NULL)
                {
                    L.pTail = p;
                    L.pTail->pNext = NULL;
                    truoc->pPrev = NULL;
                    delete truoc;
                }
                else
                {
                    p->pNext = truoc->pNext;
                    truoc->pNext->pPrev = p;
                    truoc->pNext = NULL;
                    truoc->pPrev = NULL;
                    delete truoc;
                }
                p = NULL;
                delete p;
        }
    }
}

void removeBefore(DList &L, int x)
{
    DNode *p = L.pHead;
    while (p != NULL && p->info != x)
    {
        p = p->pNext;
    }
    if(p == NULL)
    {
        cout << "\nCan't find the value "<<x;
        delete p;
    }
    else
    {
        if(p == L.pHead)
        {
            cout<<endl<<x<<" is the first element. Can't delete the element before it";
            p = NULL;
            delete p;
            return;
        }
        cout<<"\nDo you want to delete the element before "<<x<<" ?(y/n): ";
        char y;cin >> y;

        if(y == 'y' || y == 'Y')
        {
                DNode *sau = p->pPrev;
                if(sau == L.pHead)
                {
                    L.pHead = p;
                    L.pHead->pPrev = NULL;
                    sau->pNext = NULL;
                    delete sau;
                    p = NULL;
                    delete p;
                }
                else
                {
                    p->pPrev = sau->pPrev;
                    sau->pPrev->pNext = p;
                    sau->pNext = NULL;
                    sau->pPrev = NULL;
                    delete sau;
                    p = NULL;
                    delete p;
                }
        }
    }
}

void removeMultiAfters(DList &L, int x) // sai ở xóa node khi tìm thấy
{
    DNode *p = L.pHead;
    while(p != NULL && p->info != x)
    {
        p = p->pNext;
    }
    if(p == NULL)
    {
       cout << "\nCan't find the value "<<x;
        delete p; 
    }
    else if(p == L.pTail)
        {
            cout<<"\nList has only one "<<x<<" and "<<x<<" is the last element. Can't delete the element after it";
            p = p->pNext;
            delete p;
        }
        else
        {
            cout<<"\nDo you want to delete all elements after "<<x<<" ?(y/n): ";
            char y;
            cin >> y;
            if(y == 'y' || y == 'Y')
            {
                while(p->pNext != NULL)
                {
                    if(p->info == x)
                    {
                        DNode *truoc = p->pNext;
                        if(truoc == L.pTail)
                        {
                            L.pTail = p;
                            L.pTail->pNext = NULL;
                            truoc->pPrev = NULL;
                            delete truoc;
                            p = NULL;
                            delete p;
                            return;
                        }
                        else
                        {
                            p->pNext = truoc->pNext;
                            truoc->pNext->pPrev = p;
                            truoc->pNext = NULL;
                            truoc->pPrev = NULL;
                            delete truoc;
                            p = p->pNext;
                        }
                    }
                    else
                    {
                        p = p->pNext;
                    }
                }
                p = p->pNext;
                delete p;
            }
        }
}

void removeMultiBefores(DList &L, int x) // note sai khi tìm thấy ở đầu danh sách
{
    DNode *q = L.pTail;
    while(q != NULL && q->info != x)
    {
        q = q->pPrev;
    }
    if(q == NULL)
    {
        cout << "\nCan't find the value "<<x;
        delete q;
    }
    else if(q == L.pHead)
        {
            cout<<"\nList has only one "<<x<<" and "<<x<<" is the first element. Can't delete the element before it";
            q =  NULL;
            delete q;
        }
        else
        {
            cout<<"\nDo you want to delete all elements before "<<x<<" ?(y/n): ";
            char y;cin >> y;
            if(y == 'y' || y == 'Y')
            {
                DNode *p = L.pHead->pNext;
                while(p != q->pNext)
                {
                    if(p->info == x)
                    {
                     DNode *sau = p->pPrev;
                        if(sau == L.pHead)
                        {
                            L.pHead = p;
                            L.pHead->pPrev = NULL;
                            sau->pNext = NULL;
                            delete sau;
                            p = p->pNext;
                        }
                        else
                        {
                            p->pPrev = sau->pPrev;
                            sau->pPrev->pNext = p;
                            sau->pNext = NULL;
                            sau->pPrev = NULL;
                            delete sau;
                            p = p->pNext;
                        }
                    }
                    else
                    {
                        p = p->pNext;
                    }
                }
                q = NULL;
                delete q;
                p = NULL;
                delete p;
            }
        }
}


void removeAll(DList &L)
{
    cout<<"\nDo you want to delete all elements?(y/n): ";
    char y; cin >> y;
    if(y == 'y' || y == 'Y')
    {
        while(L.pHead->pNext!= NULL)
        {
            DNode *temp = L.pHead;
            L.pHead = L.pHead->pNext;
            L.pHead->pPrev = NULL;
            temp->pNext = NULL;
            delete temp;
        }
        delete L.pHead;
        init(L);
        cout<<"\nThe list becomes empty";
    }
}

void createList(DList &L)
{
    int x;
    do
    {
        cin >> x;
        if (x >= 0)
            addTail(L, x);
    } while (x >= 0);
}

void printList(DList L)
{
    DNode *p = L.pHead;
    if (L.pHead != NULL)
    {
        while (p != NULL)
        {
            cout << p->info << " ";
            p = p->pNext;
        }
    }
    else
        cout << "List is empty";
    delete p;
}



int main()
{
	DList L;
	init(L);
	int x,y,choice; char c;

	cout<<"MENU:";
    cout<<"\n1. Create a DList";
    cout<<"\n2. Print the DList";
    cout<<"\n3. Insert a value at the front";
    cout<<"\n4. Insert a value at the end";
    cout<<"\n5. Insert a value after a given value (only for the first value found)";
    cout<<"\n6. Insert a value before a given value (only for the first value found)";
    cout<<"\n7. Insert a value after a given value (for all the same values)";
    cout<<"\n8. Insert a value before a given value (for all the same values)";
    cout<<"\n9. Delete the first element";
    cout<<"\n10. Delete the last element";
    cout<<"\n11. Delete the first element containing a specific value";
    cout<<"\n12. Delete all elements storing a particular value";
    cout<<"\n13. Delete the element after a specific value (only for the first one found)";
    cout<<"\n14. Delete the element before a specific value (only for the first one found)";
    cout<<"\n15. Delete all elements after a specific value";
    cout<<"\n16. Delete all elements before a specific value";
    cout<<"\n17. Delete all elements";
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
        case 9:
            removeHead(L);
            break;
        case 10:
            removeTail(L);
            break;
        case 11:
            if (L.pHead==NULL){cout<<"\nList is empty. Can't delete";break;}
            cout<<"\nEnter a number: ";
            cin>>x;
            removeNode(L,x);
            break;
        case 12:
            if (L.pHead==NULL){cout<<"\nList is empty. Can't delete";break;}
            cout<<"\nEnter a number: ";
            cin>>x;
            removeMultiNodeS(L,x);
            break;
        case 13:
            if (L.pHead==NULL){cout<<"\nList is empty. Can't delete";break;}
            cout<<"\nEnter a number: ";
            cin>>x;
            removeAfter(L,x);
            break;
        case 14:
            if (L.pHead==NULL){cout<<"\nList is empty. Can't delete";break;}
            cout<<"\nEnter a number: ";
            cin>>x;
            removeBefore(L,x);
            break;
        case 15:
            if (L.pHead==NULL){cout<<"\nList is empty. Can't delete";break;}
            cout<<"\nEnter a number: ";
            cin>>x;
            removeMultiAfters(L,x);//sai 
            break;
        case 16:
            if (L.pHead==NULL){cout<<"\nList is empty. Can't delete";break;}
            cout<<"\nEnter a number: ";
            cin>>x;
            removeMultiBefores(L,x);// sai
            break;
        case 17:
            if (L.pHead==NULL){cout<<"\nList is empty. Can't delete";break;}
            removeAll(L);
            break;
        case 20:
            cout<<"\nGOOD BYE";
            return 0;

        }
    }

	return 0;
}