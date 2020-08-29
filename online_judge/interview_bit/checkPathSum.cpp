#include <iostream>
using namespace std;
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int hasPathSum(TreeNode* A, int B) {
    if(!A){
        return 0;
    }
    B -= A->val;
    if(!A->left && !A->right){
        return B == 0;
    }
    return hasPathSum(A->left, B) || hasPathSum(A->right, B);
}