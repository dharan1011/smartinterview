#include <iostream>
#include <vector>
#include <stack>
using namespace std;
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
vector<int> preOrderTraversal(TreeNode* A) {
    vector<int> res;
    stack<TreeNode*> stk;
    while (A || !stk.empty())
    {
        while (A)
        {
            res.push_back(A->val);
            if(A->right) stk.push(A->right);
            A = A->left;
        }
        if(!stk.empty()){
            A = stk.top();
            stk.pop();
        }
    }
    return res;
}