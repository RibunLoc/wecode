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

int depthOfTree(Tree root) // tìm chiều cao cây
{
    int depthOfTreenum = 0;
    depthOfTreenum = depth(root);

    return depthOfTreenum - 1;
}

bool CanBangTree(Node *root)
{
    if(root == NULL) return true;
    int chieucao_trai = depthOfTree(root->left);
    int chieucao_phai = depthOfTree(root->right);
    int chenh_lech = abs(chieucao_phai - chieucao_trai);
    if(chenh_lech > 1) return false;
    return CanBangTree(root->left);
    return CanBangTree(root->right);

}



int isAVL(Tree root)
{
    if(root == NULL) return 1;
    //if(/*kiểm tra đây là cây nhị phân*/) return false;
    if(!CanBangTree(root)/*cây đã cân bằng chưa */) return 0;

    return isAVL(root->left);
    return isAVL(root->right);
    
}

int main()
{
	Tree T = NULL;
	inputTree(T);
    cout<<isAVL(T);
	return 0;
}
