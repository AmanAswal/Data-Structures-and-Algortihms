#include<iostream>
using namespace std;

// declaratation of node
class Bstnode{
public:	
	int data;
	Bstnode* left;
	Bstnode* right;
};

// function for creating a node
Bstnode* GetNewNode(int data){
	Bstnode* newNode = new Bstnode();
	newNode->data=data;
	newNode->left=NULL;
	newNode->right=NULL;
	return newNode; 
}

// function for insertion
Bstnode* Insert(Bstnode* root, int data){
	if(root==NULL){
		root=GetNewNode(data);
		return root;
	}
	else if(data <= root->data){
		root->left = Insert(root->left, data);
	}
	else{
		root->right = Insert(root->right, data);
	}
	return root; 
}

// function for finding minimum element from tree
int findMin(Bstnode* root){
	if(root==NULL){
		cout<<"Error: Tree is empty\n";
		return -1;
	}
	else if(root->left==NULL){
		return root->data;
	}
	return findMin(root->left);
}

// function for finding maximum element from tree
int findMax(Bstnode* root){
	if(root==NULL){
		cout<<"Error: Tree is empty\n";
		return -1;
	}
	else if(root->right==NULL){
		return root->data;
	}
	return findMin(root->right);
}

//// function to search an element
// bool Search(Bstnode* root, int data){
// 	if(root==NULL) return false;
// 	if(root->data==data) return true;
// 	else if(data<=root->data) return Search(root->left, data);
// 	else return Search(root->right, data);
// }


int main()
{
	Bstnode* root;	// declaration of root ptr
	root=NULL;
	root=Insert(root, 50);
	root=Insert(root, 10);
	root=Insert(root, 20);
	root=Insert(root, 25);
	root=Insert(root, 8);
	root=Insert(root, 12);

	// int number;
	// cout<<"Enter number be searched\n";
	// cin>>number;
	// if(Search(root, number) == true){
	// 	cout<<"Found\n";
	// }
	// else{
	// 	cout<<"Not Found\n";
	// }

	int min = findMin(root);
	cout<<"Minimum element: "<<min<<endl;

	int max = findMax(root);
	cout<<"Maximum element: "<<max<<endl;
}