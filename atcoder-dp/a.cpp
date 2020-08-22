#include <bits/stdc++.h>
#define fast cin.sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int main(){
    fast
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    vector<int> dp(n+1);
    dp[0] = arr[0];
    dp[1] = abs(arr[1]-arr[0]);
    for(int i = 2; i < n; i++){
        dp[i] = 0;
        dp[i] += min(abs(arr[i]-dp[i-1]),abs(arr[i]-dp[i-2]));
    }
    cout << dp[n-1] << "\n";
    return 0;
}