#include <iostream>
#include <vector>
using namespace std;

void generateCombinations(int currNum, int A, int B, vector<int> &temp, vector<vector<int>> &res){
    if(temp.size() == B){
        res.push_back(temp);
        return;
    }
    for(int i = currNum; i <= A; i++){
        temp.push_back(i);
        generateCombinations(i + 1, A, B, temp, res);
        temp.pop_back();
    }
}

vector<vector<int>> combine(int A, int B) {
    vector<vector<int>> res;
    vector<int> temp;
    generateCombinations(1, A, B, temp, res);
    return res;
}

int main(){
    int A = 4;
    int B = 2;
    auto res = combine(A, B);
    for(auto &vec : res){
        for(int v : vec){
            cout << v << " ";
        }
        cout << "\n";
    }
}
