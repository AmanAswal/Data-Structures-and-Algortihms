#include<iostream>
#include<climits>
#include<queue>

using namespace std;

class BstNode {
    public:
    int data;
    BstNode* left;
    BstNode* right;
};

BstNode* getNewNode(int data){
    BstNode* newNode= new BstNode();
    newNode -> data = data;
    newNode -> left = NULL;
    newNode -> right = NULL;
    return newNode;
}

BstNode* Insert(BstNode* root, int data){
    if(root == NULL){
        root = getNewNode(data);
    }
    else if(data <= root->data){
        root->left = Insert(root->left, data);
    }
    else{
        root->right = Insert(root->right, data);
    }
    return root;
}

void levelOrder(BstNode* root){
    if(root == NULL) return;
    queue<BstNode*> Q;
    Q.push(root);
    cout<<"Level order traversal: ";
    while(!Q.empty()){
        BstNode* current = Q.front();
        cout<<current->data<<" ";
        if(current->left != NULL)
            Q.push(current->left);
        if(current->right != NULL)
            Q.push(current->right);
        Q.pop();
    }
} 

bool bst(BstNode* root, int minValue, int maxValue){
    if(root == NULL) return true;

    if(root->data > minValue && root->data < maxValue && bst(root->left, minValue, root->data) && bst(root->right, root->data, maxValue)){
        return true;
    }
    else{
        return false;
    }
}

bool isBST(BstNode* root){
    return bst(root, INT_MIN, INT_MAX);
}

int main()
{
    BstNode* root=NULL;
    root = Insert(root,2);
    root = Insert(root,1);
    root = Insert(root,3);
    // root = Insert(root,1);
    // root = Insert(root,6);
    // root = Insert(root,11);

    // cout<<"Binary tree is: ";
    // inOrder(root);    

    // levelOrder(root);
    // cout<<endl;

    if(isBST(root)){
        cout<<"This tree is BST"<<endl;
    }
    else{
        cout<<"Not a BST"<<endl;
    }
    return 0;
}
