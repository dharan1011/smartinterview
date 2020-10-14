#include <iostream>
using namespace std;
void inorder(TreeNode* root, vector<int> &l){
 if(!root){
     return;
 }
 inorder(root->left, l);
 l.push_back(root->val);
 inorder(root->right, l);
}
int Solution::kthsmallest(TreeNode* A, int B) {
    vector<int> ar;
    inorder(A, ar);
    return ar[B-1];
}
int main(int agrc, char **argv){

    return 0;
}

