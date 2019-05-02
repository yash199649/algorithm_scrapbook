#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *left;
    Node *right;
};

Node *createNode(int key){
    Node *newNode = new Node();
    newNode->data = key;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Recursive methods

void inorder(Node* root){
    if(root==NULL)
        return;
    inorder(root->left);
    cout<<root->data;
    inorder(root->right);
}

void preorder(Node* root){
    if(root==NULL)
        return;
    cout<<root->data;
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root){
    if(root==NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data;
    
}

//Level Order Traversal(Iterative)
void levelOrder(Node *root){
    if(root==NULL)
        return;
    queue<Node*> q;
    Node *temp = NULL;
    q.push(root);
    while(!q.empty()){
        temp = q.front();
        cout<<temp->data<<" ";
        q.pop();
        if(temp->left)
            q.push(temp->left);
        if(temp->right)
            q.push(temp->right);
    }
}

// Iterative Recursion


// Morris Traversal



int main(){
    Node *root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    levelOrder(root);
    return 0;
}