#include <iostream>
#include <stack>
using namespace std;
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *head, *prv;

void inOrder(TreeNode* root){
    if(!root){
        return;
    }
    stack<TreeNode *> stk;
    while (root || !stk.empty())
    {
        while (root)
        {
            // process
            if(head == NULL){
                head = root;
            }else{
                prv->left = NULL;
                prv->right = root;
            }
            prv = root;
            if(root->right){
                stk.push(root->right);
            }
            root = root->left;
        }
        if(!stk.empty()){
            root = stk.top();
            stk.pop();
        }
    }
    
}

TreeNode* flatten(TreeNode* A) {
    head = prv = NULL;
    inOrder(A);
    prv->left = NULL;
    return head;
}