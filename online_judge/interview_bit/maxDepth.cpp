#include <iostream>
using namespace std;
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int maxDepth(TreeNode* A) {
    if(!A){
        return 0;
    }
    if(!A->left && !A->right){
        return 1;
    }
    int lh = maxDepth(A->left);
    int rh = maxDepth(A->right);
    return 1 + max(lh, rh);
}