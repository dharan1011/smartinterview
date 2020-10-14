#include <iostream>
using namespace std;
void inorder(TreeNode* root, vector<int> &l){
    if(!root){
        return;
    }
    inorder(root->left, l);
    l.push_back(root->val);
    inorder(root->right, l);
}
int Solution::t2Sum(TreeNode* A, int B) {
    vector<int> ar;
    inorder(A, ar);
    int lo = 0;
    int hi = ar.size() - 1;
    while(lo < hi){
        int sum = ar[lo] + ar[hi];
        if(sum == B){
            return 1;
        }
        if(sum > B){
            hi--;
        }else{
            lo++;
        }
    }
    return 0;
}