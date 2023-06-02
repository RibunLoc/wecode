/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include <iostream>
#include <string>// 
using namespace std;

//###INSERT CODE HERE -
struct provide
{
    int ma_so;
    string sanpham;
    string chungloai;
    int namsx;
    int nambaohanh;
};
bool tieptuc = true;
struct node
{
    provide data;
    node* left;
    node* right;
};



typedef node* Tree;

node* getnode(provide x)
{
    node* newele = new node;
    if(newele != NULL)
    {
        newele->data = x;
        newele->left = NULL;
        newele->right = NULL;
    }
    return newele;
}

void addTree(Tree &root, provide x)
{
    if(root)
    {
        if(root->data.ma_so > x.ma_so)
            addTree(root->left,x);
        else if(root->data.ma_so < x.ma_so)
        {
            addTree(root->right,x);
        }
        else
        {
            cout<<"Bi trung gia tri, ket thuc qua trinh tao cay"<<endl;
            tieptuc = false;
            return;
        }
    }
    else
    {
        root = getnode(x);
    }
}



void inputTree(Tree &root)
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        if(!tieptuc)
            break;
        provide info;
        cin >> info.ma_so;
        cin.ignore();
        getline(cin,info.sanpham);
        getline(cin,info.chungloai);
        cin >> info.namsx;
        cin >> info.nambaohanh;
        addTree(root,info);
    }
    
}

void listProduct(Tree root, string type)
{
    if(root)
    {
        if(root->data.chungloai == type)
        {
            cout << root->data.ma_so <<"\t" << root->data.sanpham << "\t" << root->data.chungloai << "\t" << root->data.namsx << "\t" << root->data.nambaohanh << endl;
        }
        listProduct(root->left,type);
        listProduct(root->right,type);
    }
}

int countProduct(Tree root, int year)
{
    int count = 0;
    if(root)
    {
       if(root->data.nambaohanh > year)
        count++;

        count +=  countProduct(root->left,year);
        count += countProduct(root->right,year);
        return count;
    }
    return 0;
}
int main()
{
    Tree T = NULL;
    inputTree(T);

    string type;  cin.ignore(); getline(cin,type);
    cout<<"List of products whose type is  "<<type<<": ";
    cout<<"\nID\tName\tType\tYear\tWarranty\n";
    listProduct(T,type);

    int year;cin>>year;
    cout<<"Number of products with more than "<<year<<" years of warranty: "<<countProduct(T,year)<<endl;


	return 0;
}

