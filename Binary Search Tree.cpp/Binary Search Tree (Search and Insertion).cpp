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
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

BstNode *Insert(BstNode *root, int data)
{
    if (root == NULL){ ///Empty Tree
        root = GetNewNode(data);
    }
    else if (data <= root -> data){
        root->left = Insert(root->left, data);
    }
    else {
        root->right = Insert(root->right, data);
    }
    return root;
}

/// Inorder Traversal of BST
void Inorder(BstNode *root)
{
    if (root != NULL){
        Inorder(root->left);
        cout << root->data << endl;
        Inorder(root->right);
    }
}

bool Search(BstNode *root, int data)
{
    if (root == NULL){
        return false;
    }
    if (root -> data == data){
        return true;
    }
    else if (data <= root->data){
        Search(root->left, data);
    }
    else {
        Search(root->right, data);
    }
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

    Inorder(root);
    return 0;
}
