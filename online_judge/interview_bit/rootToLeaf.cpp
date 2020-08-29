#include <vector>
#include <iostream>
using namespace std;
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
void solve(TreeNode *root,int sum, int target, vector<int> &temp, vector<vector<int>> &res){
    if(!root){
        return;
    }
    temp.push_back(root->val);
    sum += root->val;
    if(!root->left && !root->right){
        if(sum == target){
        vector<int> r(temp.begin(), temp.end());
        temp.pop_back();
        res.push_back(r);
        return;
        }
    }
    solve(root->left,sum, target, temp, res);
    solve(root->right,sum, target, temp, res);
    temp.pop_back();
}
vector<vector<int> > pathSum(TreeNode* A, int B) {
    vector<int> temp;
    vector<vector<int>> res;
    solve(A, 0, B, temp, res);
    return res;
}