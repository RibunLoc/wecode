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
int z = 1;

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

void addtail(List &B, DONTHUC* data,int &z)
{
    if(z == 1)
    {
        init(B);
        z = 0;
    }
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

    DONTHUC* data = new DONTHUC;
    data->heso = heso;
    data->somu = somu;
    addtail(B,data,z);
    
}

void xuatdanhsach(List &B)
{
    Node* p = B.head;
    while (p != NULL)
    {
        cout << p->data->heso<< " "<< p->data->somu<< endl;
        p = p ->next;
    }
    
    
}

void Xuat(List &B)
{
    if (z == 1)
    {
        DONTHUC* data = new DONTHUC;
        data->heso = 0;
        data->somu = 1;
        addtail(B, data, z);
    }

    bool tr = true;
    bool o = true;
    bool l = false;
    Node* p = B.head;
    while (p != NULL)
    {
        if (p->data->heso == 0)
        {
            if (p->next == NULL && o)
            {
                cout << "0\n";
                return;
            }
            if (p->next != NULL && p->next->data->heso > 0 && l ) 
            {
                cout << "+";
                
            }
            l = true;
            p = p->next;
            continue;
        }
        else if (p->data->heso == 1)
        {
            if (p->data->somu == 0)
            {
                cout << "1";
            }
            else if (p->data->somu == 1)
            {
                cout << "x";
            }
            else
            {
                cout << "x^" << p->data->somu;
            }
        }
        else if (p->data->heso == -1)
        {
            if (p->data->somu == 0)
            {
                cout << "-1";
            }
            else if (p->data->somu == 1)
            {
                cout << "-x";
            }
            else
            {
                cout << "-x^" << p->data->somu;
            }
        }
        else
        {
            if (p->data->somu == 0)
            {
                cout << p->data->heso;
            }
            else if (p->data->somu == 1)
            {
                cout << p->data->heso << "x";
            }
            else
            {
                cout << p->data->heso << "x^" << p->data->somu;
            }
        }
        
        if (p->next != NULL && p->next->data->heso > 0)
        {
            cout << "+";
        }
        l = true;
        tr = false;
        o = false;
        p = p->next;
    }
    
    cout << endl;
}


double TinhDaThuc(DATHUC B, double x)
{
    double result = 0;
    Node* p = B.head;
    while(p != NULL)
    {
        result += (p->data->heso * pow(x,p->data->somu));
        p = p->next;
    }
    return result;
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
    cout << "\nVoi x=" << x << ", gia tri da thuc la: "
         << setprecision(2) << fixed << TinhDaThuc(B, x);

    return 0;
}
