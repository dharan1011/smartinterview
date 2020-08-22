#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int res;

bool check(vector<int> &grid){
    int r1 = grid[0] + grid[1] + grid[2];
    int r2 = grid[3] + grid[4] + grid[5]; 
    int r3 = grid[6] + grid[7] + grid[8];

    int c1 = grid[0] + grid[3] + grid[6];
    int c2 = grid[1] + grid[4] + grid[7]; 
    int c3 = grid[6] + grid[7] + grid[8]; 
    
    int diag = grid[0] + grid[4] + grid[8];
    return (c1 == c2) && (c2 == c3) && (c3 == r1) && (r1 == r2) && (r2 == r3) && (r3 == diag);
}

void generatePermutation(vector<int> &grid, vector<bool> taken, int index, const int N, vector<vector<int>> &s){
    if(index == N){
        if(check(grid)){
            int cost = 0;
            int t = 0;
            for(int i = 0; i < 3; i++){
                for(int j = 0; j < 3; j++){
                    cost += abs(s[i][j] - grid[t++]);
                }
            }
            res = min(res, cost);
        }
        return;
    }

    for(int i = 1; i <= N; i++){
        if(!taken[i]){
            taken[i] = true;
            grid[index] = i;
            generatePermutation(grid, taken, index + 1, N, s);
            taken[i] = false;
        }
    }
}

int formingMagicSquare(vector<vector<int>> s) {
    const int N = 9;
    res = INT_MAX;
    vector<int> arr(N,0);
    vector<bool> taken(N + 1, false);
    generatePermutation(arr, taken, 0, N, s);
    return res;
}
