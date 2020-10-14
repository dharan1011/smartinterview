#include <iostream>
using namespace std;
bool isSafe(vector<string> &grid, int row, int col, int n){
    for(int i = 0; i <= row; i++){
        if(grid[i][col] == 'Q'){
            return false;
        }
    }
    for(int i = row, j = col; i >= 0 && j >= 0; --i,--j){
        if(grid[i][j] == 'Q'){
            return false;
        }
    }
    for(int i = row, j = col; i >= 0 && j < n; --i, ++j){
        if(grid[i][j] == 'Q'){
            return false;
        }
    }
    return true;
}

void solve(vector<string> &grid, int row, vector<vector<string>> &res, int A){
    if(row == A){
        res.push_back(grid);
        return;
    }
    for(int i = 0; i < A; i++){
        if(isSafe(grid, row, i, A)){
            grid[row][i] = 'Q';
            solve(grid, row+1, res, A);
            grid[row][i] = '.';
        }
    }
}
vector<vector<string> > Solution::solveNQueens(int A) {
    vector<vector<string>> res;
    vector<string> grid(A, string(A,'.'));
    solve(grid, 0, res, A);
    return res;
}
int main(int agrc, char **argv){

    return 0;
}

