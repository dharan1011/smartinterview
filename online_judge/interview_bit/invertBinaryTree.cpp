/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <iostream>
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
TreeNode* invertTree(TreeNode* A) {
    if(!A){
        return NULL;
    }
    if(!A->left && !A->right){
        return A;
    }
    TreeNode* leftTree = invertTree(A->left);
    TreeNode* rightTree = invertTree(A->right);
    A->left = rightTree;
    A->right = leftTree;
    return A;
}