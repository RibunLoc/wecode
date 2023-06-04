/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include <iostream>
using namespace std;

//###INSERT CODE HERE - //Complete Binary Search Tree là một Full Binary Search Tree mà tất cả các nút lá đều có mức d, với d là chiều cao của cây.
struct Node
{
    int info;
    Node* pLeft;
    Node* pRight;
};

typedef Node* Tree;
Node *getNode(int x)
{
    Node *newele = new Node;
    if(newele != NULL)
    {
       newele->info = x;
       newele->pLeft = NULL;
       newele->pRight = NULL;
    }
    return newele;
}

void insertNode(Tree & T, int x)
{
    if(T)
    {
        if(T->info > x)
            insertNode(T->pLeft,x);
        else if(T->info < x)
        {
            insertNode(T->pRight,x);
        }
        else
            return;
    }
    else
    {
        T = getNode(x);
    }
}

void inputTree(Tree &T)
{
    int n ;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        insertNode(T,x);
    }
    
}

void NLR(Tree T)
{
    if(T)
    {
        cout << T->info << " ";
        NLR(T->pLeft);
        NLR(T->pRight);
    }
}

int isFullBinaryTree(Tree T)
{
    if(T == NULL)
        return 1;

    if((T->pLeft != NULL && T->pRight == NULL )|| (T->pLeft == NULL && T->pRight != NULL))
        return 0;

    if(T->pLeft != NULL && T->pRight != NULL)
    {
        return isFullBinaryTree(T->pLeft) && isFullBinaryTree(T->pRight);
    }
    return 1;
}
int lengthTree(Tree T)
{
    if(T == NULL )
        return 0;
    
    int chieu_cao_nhanh_trai = lengthTree(T->pLeft) + 1;
    int chieu_nhanh_phai = lengthTree(T->pRight) + 1;

    return max(chieu_cao_nhanh_trai,chieu_nhanh_phai) + 1 ;
}


int isCompleteBinaryTree(Tree T)
{
    if(T == NULL)
        return 1;
    
    if(T->pLeft != NULL && T->pRight == NULL || (T->pLeft == NULL && T->pRight != NULL))
        return 0;

    if(T->pLeft != NULL && T->pRight != NULL)
    {
        if(lengthTree(T->pLeft) != lengthTree(T->pRight)) return 0;
        return isCompleteBinaryTree(T->pLeft) && isCompleteBinaryTree(T->pRight);
    }
    
    return 1;

}

void LNR(Tree T)
{
    if(T)
    {
        LNR(T->pLeft);
        cout << T->info << " ";
        LNR(T->pRight);
    }
}

int main()
{
	Tree T = NULL;
	inputTree(T);
	cout<<"LNR: "; LNR(T);
	int i=isCompleteBinaryTree (T);
	if(i==0) cout<<"\nThe tree is not a Complete Binary Tree";
    else cout<<"\nThe tree is a Complete Binary Tree";
	return 0;
}


