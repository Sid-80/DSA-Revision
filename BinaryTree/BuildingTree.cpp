/*
Algoritm : 
1.Pick element from preorder and create node.
2.Increment preorder index
3.Search for picked elements position in inorder.
4.Call to build left subtree from inorder's 0 to position-1
5.Call to build right subtree from inorder position+1 to n
6.Return the node.
*/
#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int a){
        data = a;
        left = NULL;
        right = NULL;
    }
};

int search(int inorder[], int start, int end, int current){
    for (int i = start; i <= end; i++)
    {
        if (inorder[i] == current)
        {
            return i;
        }
        
    }
    return -1;
}

void inOrderPrint(Node* root){
    if (root==NULL)
    {
        return;
    }
    
    inOrderPrint(root->left);
    cout<<root->data<<" ";
    inOrderPrint(root->right);
    
}

Node* buildTree(int preorder[], int inorder[], int start, int end){
    static int index = 0;
    if (start > end)
    {
        return NULL;
    }
    
    int current = preorder[index];
    index++;
    Node* node = new Node(current);
    if (start == end)
    {
        return node;
    }
    
    int position = search(inorder, start, end, current);
    node->left = buildTree(preorder, inorder, start, position-1);
    node->right = buildTree(preorder, inorder, position+1, end);
    return node;
}

int main()
{
    int preorder[] = {1,2,4,3,5};
    int inorder[] = {4,2,1,5,3};
    //build tree
    Node* root = buildTree(preorder, inorder, 0, 4);
    inOrderPrint(root);
    return 0;
}
