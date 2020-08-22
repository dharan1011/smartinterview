#include <iostream>
#include <vector>
#define fast cin.sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#include <algorithm>
using namespace std;

void generateSubsets(vector<int> &arr, size_t idx, vector<int> &temp,vector<vector<int>> &res){
    if(idx == arr.size()){
        if(temp.empty()){
            return;
        }
        vector<int> a(temp.begin(), temp.end());
        res.push_back(a);
        return;
    }
    generateSubsets(arr, idx + 1, temp, res);
    temp.push_back(arr[idx]);
    generateSubsets(arr, idx + 1, temp, res);
    temp.pop_back();
}

vector<vector<int> > subsets(vector<int> &A) {
    sort(A.begin(), A.end());
    vector<vector<int>> res;
    vector<int> temp;
    generateSubsets(A,0,temp,res); 
    sort(res.begin(), res.end());
    return res;
}

void printVector(vector<int> &v){
    for(int x : v)
        cout << x << " ";
    cout << "\n";
}

int main(){
    fast
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int i = 0; i < n; i++)
            cin >> arr[i];
        auto res = subsets(arr);
        for(auto &vec : res){
            printVector(vec);
        }
        cout << "\n";
    }
}