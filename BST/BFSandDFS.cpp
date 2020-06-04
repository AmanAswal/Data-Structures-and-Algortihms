#include<iostream>
#include<queue>
using namespace std;

class Node{
	char data;
	Node* left;
	Node* right;
};

// BFS order function
void levelOrder(Node* root){
	if(root == NULL) return;
	queue<Node*> Q;
	Q.push(root);
	while(!Q.empty()){
		Node* current = Q.front();
		cout<<current->data<<" ";
		if(current->left != NULL){
			Q.push(current->left);
		}
		if(current->rght != NULL){
			Q.push(current->right);
		}
	}
}

// LFS order functions

// Preorder 

void preOrder(Node* root){
	if (root == NULL) return;
	cout<<root->data<<" ";
	preOrder(root->left);
	preOrder(root->right);
}

// Inorder

void inOrder(Node* root){
	if (root == NULL) return;
	inOrder(root->left);
	cout<<root->data<<" ";
	inOrder(root->right);
}

// Postorder

void postOrder(Node* root){
	if(root == NULL) return;
	postOrder(root->left);
	postOrder(root->right);
	cout<<root->data<<" ";
}

int main()
{
	
	return 0;
}