/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
class
struct
using
###End banned keyword*/
#include <iostream>
#include <tuple>
#include <utility>
using std::cin;
using std::cout;
using std::endl;
using std::pair;
using std::get;
using std::tuple;
using std::make_tuple;

struct Node{
    int val;
    Node* next;
};

struct List{
    Node *head, *tail;
};

void list_initializing(List &l){
    l.head = l.tail = NULL;
}
void add_tail(List &l, int x){
    Node*p = new Node;
    p->val = x;
    p->next = NULL;

    if (l.head == NULL){
        l.head = l.tail = p;
    } else {
        l.tail->next = p;
        l.tail = p;
    }
}

void xuat(List &l){
    for(Node *p = l.head; p != NULL; p = p->next){
        cout << p->val << " ";
    }
    cout << endl;
}


//###INSERT CODE HERE -

tuple<List, List, List> partition(List &L, int x)
{
    List nho;
    list_initializing(nho);
    List bang;
    list_initializing(bang);
    List lon;
    list_initializing(lon);

    Node *p = L.head;
    while(p != NULL)
    {
        Node *sau = p;
        if(p->val < x) // phân hoạch vào list nho;
        {
            add_tail(nho,p->val);
        }
        else if(p->val > x)
        {
            add_tail(lon,p->val);
        }
        else
        {
            add_tail(bang,p->val);
        }
        p = p->next;
        L.head = p;
        sau->next = NULL;
        delete sau;
    }
    return make_tuple(nho,bang,lon);
}

void join(List &l, List &other)
{
    Node *p = other.head;
    if(other.head != NULL)
    {
        if(l.head != NULL)
        {
            l.tail->next = other.head;
            l.tail = other.tail;
        }
        else
        {
            l.head = other.head;
            l.tail = other.tail;
        }
    }
   
    
}

int main()
{
    List l; list_initializing(l);
    cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);
    int x;
    do{
        cin >> x;
        if (x != 0) add_tail(l, x);
        else break;
    } while(true);


    do{
        cin >> x;
        if (x == 0) break;
        
        auto ls = partition(l, x);

        xuat(std::get<0>(ls));
        xuat(std::get<1>(ls));
        xuat(std::get<2>(ls));
        
        
        join(l, std::get<0>(ls));
        join(l, std::get<1>(ls));
        join(l, std::get<2>(ls));
        
    } while(true);

    return 0;
}



