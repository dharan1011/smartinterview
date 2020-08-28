#include <iostream>
#include <vector>
using namespace std;
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

 TreeNode* solve(vector<int> &A, vector<int> &B, int &pos, int lo, int hi){
    if(lo > hi || pos >= A.size()){
        return NULL;
    }
    TreeNode *currNode = new TreeNode(A[pos]);
    pos++;
    int i;
    for(i = lo; i <= hi; i++){
        if(B[i] == currNode->val){
            break;
        }
    }
    currNode->left = solve(A, B, pos, lo, i-1);
    currNode->right = solve(A, B, pos, i + 1, hi);
    return currNode;
}
TreeNode* buildTree(vector<int> &A, vector<int> &B) {
    int size = B.size();
    int lo = 0;
    int hi = size - 1;
    int pos = 0;
    return solve(A, B, pos, lo, hi);
}
