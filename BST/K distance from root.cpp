void printDistance(Node* root, int k, vector<int> &ans){
    if(root == NULL || k < 0)
        return;
    if(k == 0)
        ans.push_back(root->data);
    
    printDistance(root->left, k-1, ans);
    printDistance(root->right, k-1, ans);
}

vector<int> Kdistance(struct Node *root, int k)
{
  vector<int> ans;
  printDistance(root, k , ans);
  return ans;
}
