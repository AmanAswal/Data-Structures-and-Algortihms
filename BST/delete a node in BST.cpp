#include<iostream>
using namespace std;

// creation of NODE structure
class Node{
public:
    int data;
    Node *left;
    Node *right;
};
// Function to find the minimum node in a tree
Node* findMin(Node* root){     
     while(root-> left != NULL){
         root = root->left;
     }
     return root;
}

Node* Delete(Node* root, int data){
    if(root == NULL) return root;   //  return when No node
    else if(data < root->data){    // if node is in left side
        root->left = Delete(root->left, data); 
    }
    else if(data > root->data){     // if node is in right side
        root->right = Delete(root->right, data);
    }
    else    // Node to be deleted is found
    {
        // case 1: NO child (simply delete the node)
        if(root->left == NULL && root->right==NULL){
            delete root; // de-allocate memory of object in heap 
            root=NULL; // root pointer is still there, so set it null and return
            // return root; // reference of this node in its parent is not fixed here
        }
        // case 2: One Child
        else if(root->left == NULL){    // when left child is null
            Node* temp = root;
            root = root->right;
            delete temp;
            // return root;
        }
        else if(root->right == NULL){   // when right child is null
            Node* temp = root;
            root = root->left;
            delete temp;
            // return root;
        }
        // case 3: Two Child
        else{
            Node* temp = findMin(root->right);  // find minimum in right sub tree or maximum in left sub tree
            root->data = temp->data; // set the data of root (current) node equals to the minimum data of the node temp (or copying the minimum value to the current root)
            root->right = Delete(root->right, temp->data);
            // return root;
        }
    }
    return root;
}

Node* getNewNode(Node* root, int data){
    Node* newNode = new Node();
    newNode -> data = data;
    newNode -> right = NULL;
    newNode -> left = NULL;
    return newNode;
}

Node* Insert(Node* root, int data){
    if(root == NULL){
        root = getNewNode(root, data);
    }
    else if(root->data >= data){
        root -> left = Insert(root->left, data);
    }
    else if(root->data < data){
        root -> right = Insert(root->right, data);
    }
    return root;
}

void inOrder(Node* root){
    if(root == NULL) return; // base(exit) condition
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

int main()
{
    Node* root = NULL;

    root = Insert(root,5); root = Insert(root,10); root = Insert(root,3);
    root = Insert(root,4); root = Insert(root,1); root = Insert(root,11);

    cout<<"Original BST: ";
    inOrder(root);

    root = Delete(root,3);

    cout<<endl;
     cout<<"After deletion : ";
    inOrder(root);

    return 0;
}
