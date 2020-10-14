#include <iostream>
using namespace std;
 bool find(TreeNode *root, int B, vector<int> &path){
     if(!root){
         return false;
     }
     path.push_back(root->val);
     if(root->val == B){
         return true;
     }
     bool lc = find(root->left, B, path);
     bool rc = find(root->right, B, path);
     if(lc || rc){
         return true;
     }
     path.pop_back();
     return false;
 }
vector<int> Solution::solve(TreeNode* A, int B) {
    vector<int> res;
    find(A, B, res);
    return res;
}
int main(int agrc, char **argv){

    return 0;
}

