#include <iostream>
#include <vector>
#define fast cin.sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#include <algorithm>
using namespace std;

void generateSubsets(vector<int> &arr, int idx, vector<int> &temp,vector<vector<int>> &res){
    res.push_back(temp);
    for(int i = idx; i < arr.size(); i++){
        temp.push_back(arr[i]);
        generateSubsets(arr, i+1, temp, res);
        temp.pop_back();
    }
}

vector<vector<int> > subsets(vector<int> &A) {
    sort(A.begin(), A.end());
    vector<vector<int>> res;
    vector<int> temp;
    generateSubsets(A, 0, temp, res);
    return res;
}

int main(){
    fast
    vector<int> arr = {1,2,3};
    auto res = subsets(arr);
    for(auto v : res){
        for(int x : v)
            cout << x << " ";
        cout << "\n";
    }
}
