#include<iostream>
using namespace std;

struct Node{
	int data;
	Node* next;
};

Node* createNode(int key){
	Node* newNode = new Node();
	newNode->data = key;
	newNode->next = NULL;
	return newNode;
}

void insertNode(Node* head, int key, int position){
	Node* newNode = createNode(key);
	if(head==NULL){
		head = newNode;
		return;
	}
	else{
		int k=1;
		Node* p = head;
		Node* q;
		while(p!=NULL && k++<position){
			q=p;
			p=p->next;
		}

	}
}

void print(Node* head){
	if(head==NULL)
		return;
	Node* current = head;
	while(current!=NULL){
		cout<<current->data;
		current = current->next;
	}
}

int main(){
	Node* head = createNode(1);
	insertNode(head,2,2);
	print(head);
	return 0;
}