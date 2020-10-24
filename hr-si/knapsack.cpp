#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

void trace(vector<vector<int>> &dp, vector<int> &w, vector<int> &v, int n, int m){
    cout << "tracing" << "\n";
    int i = n;
    int j = m;
    while(i > 0){
        int mxi = i-1;
        int mxj = j;
        if(j - w[i-1] >= 0){
            if(v[i-1] + dp[i-1][j - w[i-1]] > dp[mxi][mxj]){
                mxi = i - 1;
                mxj = j - w[i-1];
                cout << w[i-1] << " " << v[i-1] << "\n";
            }
        }
        i = mxi;
        j = mxj;
    }
}

int solve(vector<int> &w, vector<int> &v, int n, int s){
    vector<vector<int>> dp(n+1, vector<int>(s+1, 0));
    for(int i = 0; i <= s; i++)
        dp[0][i] = 0;
    for(int i = 0; i <= n; i++)
        dp[i][0] = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= s; j++){
            dp[i][j] = dp[i-1][j];
            if(j - w[i-1] >= 0){
                dp[i][j] = max(dp[i][j], v[i-1] + dp[i-1][j - w[i-1]]);
            }
        }
    }
    trace(dp, w, v, n, s);
    return dp[n][s];
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int t; cin >> t;
    while(t--){
        int s, n;
        cin >> s >> n;
        vector<int> w(n), v(n);
        for(int i = 0; i < n; i++)
            cin >> w[i] >> v[i];
        cout << solve(w,v,n,s) << "\n";
    }
    return 0;
}