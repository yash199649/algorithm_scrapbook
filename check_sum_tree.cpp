#include<iostream>
#include<cstring>
using namespace std;

struct Node{
	int data;
	Node* left;
	Node* right;
};

Node* createNode(int data){
	Node* newNode = new Node();
	newNode->data=data;
	newNode->left=NULL;
	newNode->right=NULL;
	return newNode;
}

int sum(Node* root){
	if(root==NULL)
		return 0;
	return root->data+sum(root->left)+sum(root->right);
}

int isSumTree(Node* root){
    if(root==NULL || (root->left==NULL && root->right==NULL))
    	return 1;
    
    int ls=sum(root->left);
    int rs=sum(root->right);

    if(root->data==ls+rs && isSumTree(root->left) && isSumTree(root->right))
    	return 1;

    return 0;
    


}

int main(int argc, char const *argv[])
{
     struct Node *root  = createNode(26);
    root->left         = createNode(10);
    root->right        = createNode(3);
    root->left->left   = createNode(4);
    root->left->right  = createNode(6);
    root->right->right = createNode(3);
    if(isSumTree(root))
    	cout<<"YES";
    else
    	cout<<"Nope";
    return 0;
}