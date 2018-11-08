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

bool mirrorTree(Node* root1,Node* root2){
    if(root1==NULL && root2==NULL)
        return 1;
    if(root1==NULL || root2==NULL)
        return 0;

    return root1->data==root2->data && mirrorTree(root1->left,root2->right) 
    && mirrorTree(root1->right,root2->left);
}

int main(int argc, char const *argv[])
{
     Node *a = createNode(1);
    Node *b = createNode(1);
    a->left = createNode(2);
    a->right = createNode(3);
    a->left->left  = createNode(4);
    a->left->right = createNode(5);
 
    b->left = createNode(3);
    b->right = createNode(2);
    b->right->left = createNode(5);
    b->right->right = createNode(4);
 
    mirrorTree(a, b)? cout << "Yes" : cout << "No";
    return 0;
}