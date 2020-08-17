void utility(Node* root, int K, int &count, int &result){
    if(root==NULL || count>=K) return;
    
    utility(root->left, K, count, result);
    count++;
    
    if(count == K){
        result = root->data;
        return;
    }
    utility(root->right, K, count, result);
}

int KthSmallestElement(Node *root, int K)
{
    int count=0, result=-1;
    utility(root, K, count, result);
    return result;
}
