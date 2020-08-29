#include <iostream>
#include <vector>
using namespace std;
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *prv, *first, *second;

void inorder(TreeNode *root){
    if(!root){
        return;
    }
    inorder(root->left);
    if(!prv){
        prv = root;
    }else{
        if(prv->val > root->val){
            if(!first){
                first = prv;
            }
            second = root;
        }
        prv = root;
    }
    inorder(root->right);
}
// 1 2 3 4 5 6 7 9
// 1 2 3 5 4 6 7 9
vector<int> recoverTree(TreeNode* A) {
    prv = first = second = NULL;
    inorder(A);
    return {second->val, first->val};
}
