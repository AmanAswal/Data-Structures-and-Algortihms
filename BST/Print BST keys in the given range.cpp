void printUtil(Node* root, int &low, int &high, vector<int> &ans){
    if(root==NULL) return ;
    
    if(low < root->data && high < root->data){
        printUtil(root->left, low, high, ans);
    } 
    else if(low > root->data && high > root->data){
        printUtil(root->right, low, high, ans);
    }
    else{
        printUtil(root->left, low, high, ans);
        ans.push_back(root->data);
        printUtil(root->right, low, high, ans);
    }
}

vector<int> printNearNodes(Node *root, int low, int high)
{
    vector<int> ans;
    printUtil(root, low, high, ans);
    return ans;
}
