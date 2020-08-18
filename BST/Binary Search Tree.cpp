#include<iostream>
#include<queue>
using namespace std;

// Structure of BST
class Node{
public:
    int data;
    Node* left;
    Node* right;
};

// function to create a node
Node* getNewNode(int data){
    Node* newNode = new Node();
    newNode->data=data;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}

// function to insert a node
Node* Insert(Node* root, int data){
    if(root == NULL){
        root = getNewNode(data);
        return root;
    }
    else if(data <= root->data)
        root->left = Insert(root->left, data);
    else
        root->right = Insert(root->right, data);

    return root;
}

// function to search an element
bool search(Node* root, int number){
    if(root == NULL) return false;
    else if(root->data == number)
        return true;
    else if(root->data > number)
        return search(root->left, number);
    else
        return search(root->right, number);
}

// Binary Search Traversals

//D.F.S
void inOrder(Node* root){
    if(root == NULL) return;
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

void preOrder(Node* root){
    if(root == NULL) return;
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(Node* root){
    if(root == NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}

// B.F.S
void levelOrder(Node* root){
    if(root==NULL) return;
    queue<Node*> Q;
    Q.push(root);
    while(!Q.empty())
    {
        Node* current = Q.front();
        cout<<current->data<<" ";
        if(current->left != NULL)
            Q.push(current->left);
        if(current->right !=NULL)
            Q.push(current->right);
        Q.pop();
    }

}

// function for finding Minimum element
int findMin(Node* root){
    if(root == NULL) return -1;     // if no node is there
    while(root->left != NULL){
        root = root->left;
    }
    return root->data;
}

// function for finding Maximum element 
int findMax(Node* root){
    if(root == NULL) return -1;     // if no node is there
    while(root->right != NULL){
        root = root->right;
    }
    return root->data;
}

int findHeight(Node* root){
    if(root == NULL) return -1;
    int lh = findHeight(root->left);
    int rh = findHeight(root->right);

    return max(lh, rh) + 1;
}

// function to find the size of the BST or BT
int findSize(Node* root){
    if(root==NULL) return 0;
    int leftSize = findSize(root->left);
    int rightSize = findSize(root->right);
    int totalSize = leftSize + totalSize + 1;
    return totalSize;
}

// function to find the sum of the nodes of BST or BT
int findSum(Node* root){
    if(root == NULL) return 0;
    int leftSum = findSum(root->left);
    int rightSum = findSum(root->right);
    int totalSum = leftSum + rightSum + root->data;
    return totalSum;
}

int main()
{
    Node* root = NULL;

    root = Insert(root, 15); root = Insert(root, 8); root = Insert(root, 10); root = Insert(root, 25);

    // printing in inorder traversal 
    cout<<"Inorder traversal : ";
    inOrder(root);
    cout<<endl;

    // printing in preorder traversal 
    cout<<"Preorder traversal : ";
    preOrder(root);
    cout<<endl;

    // printing in Postorder traversal 
    cout<<"Postorder traversal : ";
    postOrder(root);
    cout<<endl;

    // printing in level order traversal
    cout<<"Level Order traversal: ";
    levelOrder(root);
    cout<<endl;

    // printing the maximum element in the BST
    cout<<"Minimum element is: "<<findMin(root)<<endl;
    
    // printing the minimum element in the BST
    cout<<"Maximum element is: "<<findMax(root)<<endl;

    // printing the Height of the BST
    cout<<"Height of the BST : "<<findHeight(root)<<endl;

    // printing the Size of the BST
    cout<<"Size of the BST : "<<findSize(root)<<endl;

    // printing the Sum of elements of the BST
    cout<<"Sum of all the nodes of the BST : "<<findSum(root)<<endl;
 
    // searching an element
    int number;
    cout<<"Enter a number to search: "; cin>>number;
    if(search(root, number)){
        cout<<number<<" is present"<<endl;
    } else{
        cout<<number<<" is not present"<<endl;
    }
    
    return 0;
}
