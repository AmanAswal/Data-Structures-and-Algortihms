int getSize(Node* node)
{
   if(node==NULL){
       return 0;
   }
   int lst = getSize(node->left);
   int rst = getSize(node->right);
   
   return lst+rst+1;
}
