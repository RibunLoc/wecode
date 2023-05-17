/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
[
]
define
include
###End banned keyword*/
#include<iostream>
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
int c = 1;
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

void addtail(List &B, DONTHUC* data,int &t)
{
    if(t == 1)
    {
        init(B);
        t = 0;
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
bool phuchoi = true;
int a = 0;
int b = 0;
void Nhap(List &C)
{

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        DONTHUC *data = new DONTHUC;
        cin >> data->heso;
        cin >> data->somu;
        addtail(C,data,z);
    }
    if(n == 0)
    {
        DONTHUC* data = new DONTHUC;
        data->heso = 0;
        data->somu = 1;
        addtail(C, data, z);
        z = 1;
        if(!phuchoi)
        {
            while(n == 0)
            {
                int ao1;
                int ao2;
                cin >> ao1;
                cin >> ao2;
                if(ao2 == 0)
                    break;
            }
        }
        phuchoi = false;
        return;
    }
    if(phuchoi)
    {
        z = 1;
        a = 1;
        phuchoi = false;
        return;
    }
    b = 1;

}



void Xuat(List B)
{

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
                cout << "0";
                return;
            }
            if (p->next != NULL && p->next->data->heso > 0 && l ) 
            {
                cout << "+";
                
            }
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
    
}

void xuatds(List C)
{
    Node* p = C.head;
    while(p != NULL)
    {
        cout << p->data->heso<<" "<< p->data->somu<< endl;
        p = p->next;
    }
}


DATHUC Tong2DaThuc(DATHUC A, DATHUC B)
{
    DATHUC C;
    if(a == 0 && b == 0)
    {
        DONTHUC* newC = new DONTHUC;
        newC->heso = 0;
        newC->somu = 1;
        addtail(C,newC,c);
        return C;
    }
    if(a == 0) return B;
    if(b == 0) return A;

    Node* p = A.head;
    Node* q = B.head;

    while(p!= NULL & q != NULL)
    {
        DONTHUC* newdata = new DONTHUC;
        if(p->data->somu > q->data->somu)
        {
            newdata->heso = p->data->heso;
            newdata->somu = p->data->somu;
            addtail(C,newdata,c);
            p = p->next;
        }
        else if(p->data->somu < q->data->somu)
        {
            newdata->heso = q->data->heso;
            newdata->somu = q->data->somu;
            addtail(C,newdata,c);
            q = q->next;
        }
        else 
        {
            newdata->heso = q->data->heso + p->data->heso;
            newdata->somu = p->data->somu;
            addtail(C,newdata,c);
            p = p->next;
            q = q->next;
        }
    }

    while(p != NULL)
    {
        DONTHUC* newdata = new DONTHUC;
        newdata->heso = p->data->heso;
        newdata->somu = p->data->somu;
        addtail(C,newdata,c);
        p = p->next;
    }

    while(q != NULL)
    {
        DONTHUC* newdata = new DONTHUC;
        newdata->heso = q->data->heso;
        newdata->somu = q->data->somu;
        addtail(C,newdata,c);
        q = q->next;
    }

    return C;
}


int main() {
    DATHUC A, B;
    Nhap(A);
    Nhap(B);
    cout << "Da thuc A: "; Xuat(A);
    cout << "\nDa thuc B: "; Xuat(B);
    cout << "\nA+B = "; Xuat(Tong2DaThuc(A, B));

    return 0;
}
