#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve(vector<int> &arr, int n){
    for(int i = 1; i < n; i++){
        int key = arr[i];
        int j = i-1;
        while(j >= 0 && arr[j] > key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
        cout << j+1 << " ";
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