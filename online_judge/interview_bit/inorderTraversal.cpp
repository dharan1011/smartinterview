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
vector<int> inorderTraversal(TreeNode* A) {
    vector<int> res;
    stack<TreeNode*> stk;
    while (A || !stk.empty())
    {
        while (A)
        {
            stk.push(A);
            A = A->left;
        }
        if(!stk.empty()){
            auto t = stk.top();
            stk.pop();
            res.push_back(t->val);
            A = t->right;
        }
    }
    return res;
}