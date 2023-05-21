/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include <iostream>
using namespace std;

//###INSERT CODE HERE -

struct Node
{
    int data;
    Node *left;
    Node *right;
};

typedef Node* Tree;

Node* getnode(int x)
{
    Node *p = new Node;
    if(p != NULL)
    {
        p->data = x;
        p->left = NULL;
        p->right = NULL;
    }
    return p;
}

void AddNode(Tree &root, int x)
{
    if(root != NULL)
    {
        if(root->data == x) return; // tìm thấy không thêm
        if(x < root->data) // thêm bên trái 
            AddNode(root->left, x);
        else
            AddNode(root->right,x);
    }
    else
    {
        root = getnode(x); // đã tìm thấy
    }
}

void inputTree(Tree &T)
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        AddNode(T,x);
    }  
} 

void LNR(Tree root) 
{
    if(root)
    {
        LNR(root->left);
        cout<< root->data<< " ";
        LNR(root->right);
    }
}

int countNodes(Tree root)
{
    if(root)
        return countNodes(root->left) + countNodes(root->right) + 1 ;
    else 
        return 0;
}

int depth(Tree root)
{
    if(root)
    {
        int depthOfTree_left = depth(root->left);
        int depthOfTree_right = depth(root->right);
        return max(depthOfTree_left,depthOfTree_right) + 1;
    }   
    else
        return 0;
}


int depthOfTree(Tree root)
{
    int depthOfTreenum = 0;
    depthOfTreenum = depth(root);

    return depthOfTreenum - 1;
}

int countEven(Tree root, int &count_even)
{
    if(root)
    {
        if(root->data % 2 == 0) ++count_even;
        count_even = countEven(root->left,count_even);
        count_even = countEven(root->right,count_even);
    }
   

    
    return count_even;
}

int countOdd(Tree root, int &count_odd)
{
    if(root)
    {
        if(root->data % 2 != 0) ++count_odd;
        count_odd = countOdd(root->left,count_odd);
        count_odd = countOdd(root->right,count_odd);
    }
    
    return count_odd;
}

int countPositive(Tree root)
{
    if(root == NULL ) return 0;
    int count = 0;

    if(root->data > 0)
        ++count;

    count +=  countPositive(root->left);
    count += countPositive(root->right);

    return count;
}


int countNegative(Tree root)
{
    if(root == NULL) return 0;
    int count = 0;

    if(root->data < 0)
        ++count;

    count +=  countNegative(root->left);
    count += countNegative(root->right);

    return count;
}

bool ktrsoNT(int x)
{
   if (x < 2) return false;
    for (int i = 2; i*i <= x; ++i) {
        if (x % i == 0) return false;
    }
    return true;
    
}

int countPrime(Tree root)
{
    if(root == NULL ) return 0;

    int count = 0;

    if(ktrsoNT(root->data))
    {
        ++count;
    }

    count +=  countPrime(root->left);
    count += countPrime(root->right);

    return count;
}

void listPrime(Tree root)
{
    if(root == NULL) return;

    if(ktrsoNT(root->data))
        cout << root->data << " ";

    listPrime(root->left);
    listPrime(root->right);

}

int main()
{
	Tree T = NULL;
	inputTree(T);
    cout<<"LNR: "; LNR(T); cout<<endl;

	cout<<"Number of nodes: " << countNodes(T)<<endl;
    cout<<"Depth of Tree: "<<depthOfTree(T)<<endl;

    int count_even = 0, count_odd =0;
    countEven(T, count_even);countOdd(T, count_odd);
    cout<<"Number of even nodes: "<<count_even<<endl;
    cout<<"Number of odd nodes: "<<count_odd<<endl;

    cout<<"Number of positive nodes: "<<countPositive(T)<<endl;
    cout<<"Number of negative nodes: "<<countNegative(T)<<endl;

    cout<<"Number of prime nodes: "<<countPrime(T)<<endl;
    cout<<"Prime numbers: "; listPrime(T);



	return 0;
}
