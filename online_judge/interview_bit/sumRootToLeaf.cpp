#include <iostream>
using namespace std;
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
// Problem with MODULO
void solve(TreeNode *root, int sum, int &res){
    if(!root){
        return;
    }
    sum = sum * 10 + root->val;
    if(!root->left && !root->right){
        res += (abs(sum) % 1003);
        return;
    }
    solve(root->left, sum, res);
    solve(root->right, sum, res);
}

int sumNumbers(TreeNode* A) {
    int res = 0;
    solve(A, 0, res);
    return res % 1003;
}