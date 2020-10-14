#include <iostream>
using namespace std;

stack<TreeNode*> stk;
BSTIterator::BSTIterator(TreeNode *root) {
    while(root){
        stk.push(root);
        root = root->left;
    }
}

/** @return whether we have a next smallest number */
bool BSTIterator::hasNext() {
    return !stk.empty();
}

/** @return the next smallest number */
int BSTIterator::next() {
    TreeNode* root = stk.top(); stk.pop();
    int rv = root->val;
    root = root->right;
    while(root){
        stk.push(root);
        root = root->left;
    }
    return rv;
}

int main(int agrc, char **argv){

    return 0;
}

