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
    int data;
    node* next;
};

struct List
{
    node* head;
    node* tail;
};

node* getnode(int x)
{
    node *newele = new node;
    if(newele != NULL)
    {
        newele->data = x;
        newele->next = NULL;
    }
    return newele;
}
void Init(List &L)
{
    L.head = NULL;
    L.tail = NULL;
}

void addtail(List &L, int x)
{
    node *newnode = getnode(x);
    if(L.head == NULL)
        L.head = L.tail = newnode;
    else
    {
        L.tail->next = newnode;
        L.tail = newnode;
    }
}
void addhead(List &L, int x)
{
    node *newnode = getnode(x);
    if(L.head == NULL)
        L.head = L.tail = newnode;
    else
    {
        newnode->next = L.head;
        L.head = newnode;
    }
}
void deletehead(List &L)
{
    if(L.head == NULL)
        return;
    else
    {
        node* p = L.head;
        L.head = p->next;
        p->next = NULL;
        delete p;
        if(L.head == NULL) L.tail = NULL;
    }
}

void deletetail(List &L)
{
    if(L.head == NULL)
        return;
    else
    {
        node* p = L.head;
        if(L.head == L.tail)
        {
            deletehead(L);
        }
        else
        {
            node *sau = NULL;
            while(p->next != NULL)
            {
                sau = p;
                p = p->next;
            }
            if(sau != NULL)
            {
                L.tail = sau;
                L.tail->next = NULL;
            }
            else
            {
                L.tail = NULL;
                L.head = NULL;
            }
        }
    }
}

void addfind(List &L, int a, int b)
{
    node* p = L.head;
        if(L.head == NULL)
        {
            addhead(L,b);
        }
        else{
        while(p->next != NULL && p->data != a)
        {
            p = p->next;
        }
        if(p->next == NULL && p->data != a)
        {
            addhead(L,b);
        }
        else
        {
            if(p->data == a && p->next == NULL)
            {
                addtail(L,b);
            }
            else
            {
                node* newnode = getnode(b);
                newnode->next = p->next;
                p->next = newnode;
            }
        }
        }
        p = NULL;
    delete p;
}

void deletefind(List &L, int a)
{
    if(L.head == NULL)
       return; 
    
    node* p = L.head;
    node* sau = NULL;
    if(p->data == a)
    {
        deletehead(L);
        p = NULL;
        delete p;
        delete sau;
        return;
    }
        while(p->next != NULL && p->data != a)
        {
            sau = p;
            p = p->next;
        }
        if(p->next == NULL && p->data != a){
            p = NULL;
        }
        else
        {   
            if(p->next == NULL && p->data == a) 
            {
                deletetail(L);
                p = NULL;
            }
            else
            {
                sau->next = p->next;
                p->next = NULL;  
            }
        }
    sau = NULL;
    delete sau;
    delete p;
}

void deleteN(List &L, int n)
{
    if(L.head == NULL)
        return;
    else
    {
        node* p = L.head;
        node* sau = NULL;
        while (p != NULL)
        {
            if(p->data == n)
            {
                if(p == L.head)
                {
                    deletehead(L);
                    p = L.head;
                }
                else if(p == L.tail)
                    {
                        deletetail(L);
                        p = NULL;
                    }
                    else
                    {
                        sau->next = p->next;
                        p = p->next;
                    }
                    
            }
            else
            {
                sau = p;
                p = p->next;
            }
        }
        p = NULL;
        sau = NULL;
        delete p;
        delete sau;
    }
}

void inputList(List &L, int n)
{   
   char x,y;
   int z;
   for (int i = 0; i < n; i++)
   {
     cin >> x; cin >> y;
    cin >> z;
    if(x == '+')
    {
        if(y == 'T')
        {
            addtail(L,z);
        }
        else
        {
            addhead(L,z);
        }
    }
    else
    {
        if(y == 'H')
        {
            deletehead(L);
        }
        else
        {
            deletetail(L);
        }
    }
   }
   
  
}


void outputList(List L)
{
    if(L.head == NULL)
        cout << "blank"<<endl;
    else
    {
        node* p = L.head;
        while(p != NULL)
        {
            cout <<p->data << " ";
            p = p->next;
        }
    }
}


int main()
{
    List L; // Khai bao 1 danh sach
    Init(L); // Khoi tao danh sach
    int choice;
    do
    {
        cin >> choice;
        switch (choice)
        {
        case 0: // addhead
            {  
                int x;
                cin >> x;
                addhead(L,x);
                break;
            }
        case 1:
           {
                int x;
                cin >> x;
                addtail(L,x);
                break;
           } 
        case 2: // tìm vị trí a xuất hiện thêm số b vào sau đó ,không có thêm đầu   
            {
                int a,b;
                cin >> a;
                cin >> b;
                addfind(L,a,b);
                break;
            }
        case 3: // tìm số này và xóa đi
            {
                int xoa;
                cin >> xoa;
                deletefind(L,xoa);
                break;
            }
        case 4: // xóa tất cả n ra khỏi danh sách
            {
                int n;
                cin >> n;
                deleteN(L,n);
                break;
            }
        case 5:
            {
                deletehead(L);
                break;
            }
        case 6:
                break;
            
        default:
            break;
        }
    } while (choice != 6);
    
    

    outputList(L);

    return 0;
}
