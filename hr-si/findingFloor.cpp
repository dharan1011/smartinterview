#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#define fast cin.sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

void solve(vector<int> &arr, int x){
    int ans = INT_MIN;
    int lo = 0;
    int hi = arr.size() - 1;
    while(lo <= hi){
        int mid = lo + (hi - lo) / 2;
        if(arr[mid] <= x){
            ans = arr[mid];
            lo = mid + 1;
        }else{
            hi = mid - 1; 
        }
    }
    cout << ans << "\n";
}

int main(){
    fast
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr.begin(), arr.end());
    int Q;
    cin >> Q;
    while(Q--){
        int x;
        cin >> x;
        solve(arr,x);
    }
}