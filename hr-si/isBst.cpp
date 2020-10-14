#include <vector>
#include <iostream>
#include <climits>
#define fast cin.sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int left(int idx){
    return 2 * idx + 1;
}

int right(int idx){
   return 2 * idx + 2;
}

bool solve(int root, int lb, int ub,vector<int> &tree, int n){
    if(root >= n){
        return true;
    }
    if(tree[root] <= lb || tree[root] >= ub){
        return false;
    }
    int lr = left(root);
    int rr = right(root);
    return solve(lr,lb,tree[root],tree,n) && solve(rr,tree[root],ub,tree,n);
}

int main(){
    fast
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> ar(n);
        for(int i = 0; i < n; i++)
            cin >> ar[i];
        if(solve(0,INT_MIN,INT_MAX,ar,n)){
            cout << "True";
        }else{
            cout << "False";
        }
        cout << "\n";
    }
}