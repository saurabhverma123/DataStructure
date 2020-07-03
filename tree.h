#ifndef TREE_H
#define TREE_H
#include<iostream>
#include<queue>
using namespace std;


template <class T>
struct TreeNode{
    T data;
    TreeNode *left;
    TreeNode *right;
};

template <class T>
TreeNode<T>* getNewNode(T data)
{
    TreeNode<T>* newNode = new TreeNode<T>;
    newNode->data=data;
    newNode->left=nullptr;
    newNode->right=nullptr;
    return newNode;
}

template <class T>
void addNode(TreeNode<T>** head, int data)
{
    if (*head == nullptr)
    {
        TreeNode<T>* newNode = getNewNode(data);
        *head = newNode;
        return ;
    }
    TreeNode<T>* root = *head;
    if (root->data >= data )
        root->left = addNodeUtil(root->left, data);
    else
        root->right = addNodeUtil(root->right, data);
}

template <class T>
TreeNode<T>* addNodeUtil(TreeNode<T>* head, int data)
{
    if (head == nullptr)
    {
        TreeNode<T>* newNode = getNewNode(data);
        return newNode;
    }
    else
    {
        if (head->data >= data)
            head->left = addNodeUtil(head->left, data);
        else
            head->right = addNodeUtil(head->right, data);
    }
    return head;

}
template <class T>
void printLevelOrderTraversal(TreeNode<T>* head)
{
    queue<TreeNode<T>*> q;
    if (head == nullptr)
        return;
    q.push(head);
    while (!q.empty())
    {
        TreeNode<T>* curr = q.front();
        q.pop();
        cout << curr->data <<"   ";
        if (curr->left)
            q.push(head->left);
        if (curr->right)
            q.push(head->right);
    }
}

template <class T>
void inOrderPrintTree(TreeNode<T>* head)
{
    if (head != nullptr)
    {
        inOrderPrintTree(head->left);
        cout << head->data << endl;
        inOrderPrintTree(head->right);
    }
}

template <class T>
void postOrderPrintTree(TreeNode<T>* head)
{
    if (head != nullptr)
    {
        postOrderPrintTree(head->left);
        postOrderPrintTree(head->right);
        cout << head->data << endl;
    }
}


template <class T>
void preOrderPrintTree(TreeNode<T>* head)
{
    if (head != nullptr)
    {
        cout << head->data << endl;
        preOrderPrintTree(head->left);
        preOrderPrintTree(head->right);
    }
}
///////////////////////////// is binary search tree
template <class T>
bool isBSTUtil(TreeNode<T> *head, int min, int max)
{
    bool retVal{true};
    if (head)
    {
        if (head->data >= min && head->data < max)
        {
            retVal =  isBSTUtil(head->left, min, head->data) && isBSTUtil(head->right, head->data, max);
        }
        else
            retVal = false;
    }
    return retVal;

}
// is binary search tree
template <class T>
bool isBST(TreeNode<T> *head)
{
    bool retVal{true};
    retVal = isBSTUtil(head, INT_MIN, INT_MAX);
    return retVal;
}

// common ancestor
// balance a binary tree
// LRU
// delte a node in BST
// Find a pair with given sum in a Balanced BST
// Zigzag traversal of binary tree


void treeRun()
{
    TreeNode<int>* head= nullptr;
    addNode(&head, 10);
    addNode(&head, 5);
    addNode(&head, 15);
    cout << "-----in order------\n";
    inOrderPrintTree(head);
    cout << "-----pre order------\n";
    preOrderPrintTree(head);
    cout << "-----post order------\n";
    postOrderPrintTree(head);
    cout << "-----Level order------\n";
    printLevelOrderTraversal(head);
    cout  << "------------\n";
    if (isBST(head))
    {
        cout << "THis is a BST \n";
    }
    else
        cout << "THis is not a BST \n";
}

#endif // TREE_H
