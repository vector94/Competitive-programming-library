#include <bits/stdc++.h>
using namespace std;

struct BstNode
{
    int data;
    BstNode *left;
    BstNode *right;
};

BstNode *GetNewNode(int data)
{
    BstNode *newNode = new BstNode();
    newNode -> data = data;
    newNode -> left = NULL;
    newNode -> right = NULL;
    return newNode;
}

BstNode *Insert(BstNode *root, int data)
{
    if (root == NULL){
        root = GetNewNode(data);
    }
    else if (data <= root -> data){
        root -> left = Insert(root->left, data);
    }
    else {
        root -> right = Insert(root -> right, data);
    }
    return root;
}

///Finding Minimum Element
int FindMin(BstNode *root)
{
    if (root == NULL){ ///Empty Tree
        cout << "Empty Tree\n";
        return -1;
    }
    else if (root -> left == NULL){
        return root->data;
    }
    FindMin(root->left);
}

///Finding Maximum Element
int FindMax(BstNode *root)
{
    if (root == NULL){ ///Empty Tree
        cout << "Empty Tree\n";
    }
    else if (root -> right == NULL){
        return root->data;
    }
    FindMax(root->right);
}

int main ()
{
    BstNode *root = NULL;
    root = Insert(root, 50);
    root = Insert(root, 30);
    root = Insert(root, 20);
    root = Insert(root, 40);
    root = Insert(root, 70);
    root = Insert(root, 60);
    root = Insert(root, 80);

    cout << FindMin(root) << endl;
    cout << FindMax(root) << endl;
    return 0;
}
