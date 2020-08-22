#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

// partition in k contigoius block

int ans = 0;
void solve(int arr[], int N, int K, int currSum, int index){
    int localSum = 0;
    if(K == 1){
        for(int i = index; i < N; i++){
            localSum += arr[i];
        }
        currSum = max(currSum, localSum);
        ans = min(ans, currSum);
        return;
    }
    for(int i = index; i < N; i++){
        localSum += arr[i];
        currSum = max(currSum, localSum);
        solve(arr, N, K-1, currSum, i + 1);
    }
}

void minimizeKPartition(int arr[], int N, int K){
    ans = INT_MAX;
    solve(arr, N, K, 0, 0);
    cout << ans << "\n";
}

int main(int agrc, char **argv){
    
    return 0;
}