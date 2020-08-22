#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve(vector<int> &arr, int n){
    for(int i = n - 1; i >= 1; --i){
        int mx = i;
        for(int j = i - 1; j >= 0; --j){
            if(arr[j] >= arr[mx]){
                mx = j;
            }
        }
        swap(arr[mx],arr[i]);
        cout << mx << " ";
    }
    cout << "\n";
}

int main(){
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int i = 0; i < n; i++)
            cin >> arr[i];
        solve(arr, n);
    }
}