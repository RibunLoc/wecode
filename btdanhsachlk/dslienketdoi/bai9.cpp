/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
[
]
define
include
###End banned keyword*/
#include<iostream>
#include<cmath>
#include <iomanip>
using namespace std;


struct DONTHUC{
	int somu;
	double heso;
};


struct Node{
	DONTHUC* data;
	Node* next;

};

typedef struct DATHUC{
	Node* head;
	Node* tail;
}List;
 
//###INSERT CODE HERE -

void init(List &B)
{
    B.head = NULL;
    B.tail = NULL;
}

Node* getnode(DONTHUC* data)
{
    Node* newele = new Node;
    if(newele != NULL)
    {
        newele->data = data;
        newele->next = NULL;
    }
    return newele;
}

void addtail(List &B, DONTHUC* data)
{

    Node* newnode = getnode(data);
    if(B.head == NULL)
        B.head = B.tail = newnode;
    else
    {
        B.tail->next = newnode;
        B.tail = newnode;
    }
}

void Nhap(List &B, double heso, int somu)
{
    if(B.head != B.tail && B.head->next == NULL)
    {
        B.head = NULL;
        B.tail = NULL;
    }//////
    
    DONTHUC* data = new DONTHUC;
    data->heso = heso;
    data->somu = somu;
    addtail(B,data);
    
}

void Xuat(List B)
{
    if(B.head == NULL)
        return;
    else
    {
        Node* p = B.head;
        while(p != NULL)
        {
            cout << p->data->heso <<"x^"<<p->data->somu;
            if(p->next != NULL && p->next->data->heso > 0)
            {
                cout << "+";
            }
            else if(p->next != NULL && p->next->data->heso == 0)
                {
                    cout << "";
                }
                else if(p->next != NULL)
                    cout << " ";
            
            p = p->next;
        }
    }
}

int main() {
    DATHUC B;
    int n; cin >> n;
    double heso; int somu;
    for (int i = 0; i < n; i++)
    {
		cin >> heso >> somu;
		Nhap(B,heso,somu);
    }
    cout << "Da thuc vua nhap la: "; Xuat(B);
    double x; cin >> x;
    cout << "\nVoi x=" << x << ", gia tri da thuc la: ";
    //     << setprecision(2) << fixed << TinhDaThuc(B, x);
    return 0;
}
