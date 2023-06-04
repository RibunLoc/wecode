/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include <iostream>
using namespace std;

//###INSERT CODE HERE - // tìm phần tử lớn thứ 2 trong cây
struct Node
{
    int info;
    Node *pLeft;
    Node *pRight;
};
typedef struct Node* Tree;
Node* getNode(int x)
{
    Node* newele = new Node;
    if(newele != NULL)
    {
        newele->info = x;
        newele->pLeft = NULL;
        newele->pRight = NULL;
    }
    return newele;
}

void insertNode(Tree &T, int x)
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
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        insertNode(T,x);
    }
}

int findMax(Tree T)
{
    if(T == NULL)
        return 0;
    int max_val = T->info;
    int max_left = findMax(T->pLeft);
    int max_right = findMax(T->pRight);

    max_val = max(max_left,max_val);
    max_val = max(max_right,max_val);

    return max_val;
}

void secondLargest(Tree T)
{
    if(T == NULL || (T->pLeft == NULL && T->pRight == NULL))
        return;
    
    int max = findMax(T);
    int max_2 = -100;
    
    while(T != NULL)
    {
        if(T->info > max_2 && T->info < max)
            max_2 = T->info;
        
        if(T->info == max)
        {
            if(T->pLeft != NULL)
            {
                int temp = findMax(T->pLeft);
                if(temp > max_2)
                    max_2 = temp;
            }
            
            if(T->pRight != NULL)
            {
                int temp = findMax(T->pRight);
                if(temp > max_2)
                    max_2 = temp;
            }
            break;
        }

        if(T->info > max)
            T = T->pLeft;
        else
            T = T->pRight;
    }

    cout <<"2nd largest value is "<< max_2 << " ";
}


int main()
{
	Tree T = NULL;
	inputTree(T);
    secondLargest(T);
	return 0;
}
