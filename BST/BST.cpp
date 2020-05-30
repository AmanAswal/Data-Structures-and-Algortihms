#include<iostream>
using namespace std;

class Bstnode{
public:	
	int data;
	Bstnode* left;
	Bstnode* right;
};

Bstnode* GetNewNode(int data){
	Bstnode* newNode = new Bstnode();
	newNode->data=data;
	newNode->left=NULL;
	newNode->right=NULL;
	return newNode; 
}

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

bool Search(Bstnode* root, int data){
	if(root==NULL) return false;
	if(root->data==data) return true;
	else if(data<=root->data) return Search(root->left, data);
	else return Search(root->right, data);
}

int main()
{
	Bstnode* root;
	root=NULL;
	root=Insert(root, 15);
	root=Insert(root, 10);
	root=Insert(root, 20);
	root=Insert(root, 25);
	root=Insert(root, 8);
	root=Insert(root, 12);

	int number;
	cout<<"Enter number be searched\n";
	cin>>number;
	if(Search(root, number) == true){
		cout<<"Found\n";
	}
	else{
		cout<<"Not Found\n";
	}
}

