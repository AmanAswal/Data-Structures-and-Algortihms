#include<iostream>
#include<climits>
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

// function to find minimum in a tree
Bstnode* FindMin(Bstnode* root){
	while(root->left != NULL)
		root = root->left;
	return root;
}

// function for deletion of node
Bstnode* Delete(Bstnode* root, int data){
	if(root==NULL) return root;
	else if(data < root->data){
		root->left = Delete(root->left, data);
	}
	else if(data > root->data){
		root->right = Delete(root->right, data);
	}
	else{
		if(root->left==NULL && root->right==NULL){
			delete (root);
			root=NULL;
		}
		else if(root->left==NULL){
			Bstnode* temp= root;
			root=root->right;
			delete(temp);
		}
		else if(root->right==NULL){
			Bstnode* temp= root;
			root=root->left;
			delete(temp);
		}
		else{
			Bstnode* temp = FindMin(root->right);
			root->data = temp->data;
			root->right=Delete(root->right, temp->data);
		}
	}
	return root;
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

// function to search an element
bool Search(Bstnode* root, int data){
	if(root==NULL) return false;
	if(root->data==data) return true;
	else if(data<=root->data) return Search(root->left, data);
	else return Search(root->right, data);
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

// function to find height of the Tree

int findHeight(Bstnode* root){
	if(root==NULL){
		return -1;
	}
	return max(findHeight(root->left), findHeight(root->right)) + 1;
}

// function to check if the Binary tree is BST or not
bool IsBstUtil(Bstnode* root, int minValue, int maxValue){
	if (root==NULL) return true;

	if(root->data > minValue && root->data < maxValue
		&& IsBstUtil(root->left, minValue, root->data)
		&& IsBstUtil(root->right, root->data, maxValue))
		return true;
	else
		return false;
}

bool IsBinarySearchTree(Bstnode* root){
	return IsBstUtil(root, INT_MIN, INT_MAX);
}

int main()
{
	Bstnode* root;
	root=NULL;
	root=Insert(root, 15);
	root=Insert(root, 10);
	root=Insert(root, 20);
	root=Insert(root, 5);
	root=Insert(root, 8);
	root=Insert(root, 12);
	root=Insert(root, 13);
	root = Delete(root,5);

	int number;
	cout<<"Enter number be searched: ";
	cin>>number;
	if(Search(root, number) == true){
		cout<<"Found!\n\n";
	}
	else{
		cout<<"Not Found!\n\n";
	}

	int min = findMin(root);
	cout<<"Minimum element in the tree: "<<min<<endl;

	int max = findMax(root);
	cout<<"Maximum element in the tree: "<<max<<endl;

	int height = findHeight(root);
	cout<<"Height of the Tree: "<<height<<endl;

	if(IsBinarySearchTree(root)){
		cout<<"This is a Binary Search Tree.";
	}

	return 0;
}

