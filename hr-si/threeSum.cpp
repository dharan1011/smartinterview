#include <iostream>
#include <vector>
#include <algorithm>
#define fast cin.sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
bool two_pointer(vector<int> &arr,int lo, int hi, int target){
    while(lo < hi){
        int sum = arr[lo] + arr[hi];
        if(sum == target){
            return true;
        }
        if(sum < target){
            lo++;
        }else{
            hi--;
        }
    }
    return false;
}

void solve(vector<int> &arr, int target){
    sort(arr.begin(), arr.end());
    //a + b + c = target
    //a + b = target - c
    // let target - c = k
    // a + b = k
    int n = arr.size();
    for(int i = 0; i < n; i++){
        int c = arr[i];
        int k = target - c;
        if(two_pointer(arr, i+1, n-1, k)){
            cout << "true" << "\n";
            return;
        }
    }
    cout << "false" << "\n";
}

int main(){
    fast
    int T;
    cin >> T;
    while(T--){
        int n, x;
        cin >> n >> x;
        vector<int> arr(n);
        for(int i = 0; i < n; i++)
            cin >> arr[i];
        solve(arr, x);
    }
    return 0;
}