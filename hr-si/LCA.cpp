#include <vector>
#include <iostream>
#include <climits>
#define fast cin.sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int _val) : val {_val}, left{nullptr}, right{nullptr} {}
};

TreeNode* insert(TreeNode* root, int val){
    if(!root){
        return new TreeNode(val);
    }
    if(val > root->val){
        root->right = insert(root->right, val);
    }else{
        root->left = insert(root->left, val);
    }
    return root;
}


bool findPath(TreeNode* root, int val, vector<int> &path){
    if(!root){
        return false;
    }
    path.push_back(root->val);
    if(root->val == val) return true;
    if(findPath(root->left, val, path) || findPath(root->right, val, path)){
        return true;
    }
    path.pop_back();
    return false;
}

int lca(TreeNode* root, int u, int v){
    vector<int> pathU {};
    vector<int> pathV {};
    findPath(root, u, pathU);
    findPath(root, v, pathV);
    // for(int x : pathU) cout << x << " ";
    // cout << "\n";
    // for(int x : pathV) cout << x << " ";
    // cout << "\n";
    // cout << pathU.size() << "\n";
    // cout << pathU.size() << "\n";
    int i;
    for(i = 0; i < min(pathU.size(), pathV.size()); i++){
        if(pathU[i] != pathV[i]){
            break;
        }
    }
    return pathU[i-1];
}

int main(){
    fast
    int t; cin >> t;
    while(t--){
        int n, q;
        cin >> n >> q;
        TreeNode *root = nullptr;
        for(int i = 0; i < n; i++){
            int x; cin >> x;
            root = insert(root, x);
        }
        for(int i = 0; i < q; i++){
            int u, v; cin >> u >> v;
            cout << lca(root,u,v) << " ";
        }
        cout << "\n";
    }
    return 0;
}