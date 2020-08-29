#include <iostream>
#include <queue>
using namespace std;
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int minDepth(TreeNode* A) {
    // Level Order and First Leaf Node
    if(!A){
        return 0;
    }
    queue<TreeNode *> q;
    q.push(A);
    int depth = 1;
    while (!q.empty())
    {
        int n = q.size();
        for(int i = 0; i < n; i++){
            TreeNode *curr = q.front();
            q.pop();
            if(!curr->left && !curr->right){
                return depth;
            }
            if(curr->left)
                q.push(curr->left);
            if(curr->right)
                q.push(curr->right);
        }
        depth++;
    }
    return depth;
}