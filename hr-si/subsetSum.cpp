#include <iostream>
#include <vector>
using namespace std;

/*
These Problem has three solution
1. Genrating all subset and checking each subset sum
2. Using Recursion which is implemeted below
3. DP as the problem has overlapping subproblem
*/

bool solve(vector<int> &arr, int idx, int currSum, int n, int s)
{
    // if (idx == n)
    // {
    //     return (currSum == s);
    // }
    // if (solve(arr, idx + 1, currSum, n, s))
    // {
    //     return true;
    // }
    // return solve(arr, idx + 1, currSum + arr[idx], n, s);
    vector<vector<bool>> dp(n + 1, vector<bool>(s + 1, false));
    dp[0][0] = true; // size and sum == 0
    for (int i = 1; i <= n; i++)
    {
        dp[i][0] = true; // sum is zero and vector size > 0
    }
    for (int i = 1; i <= s; i++)
    {
        dp[0][s] = false; // vector size of size is zero but sum > 0, false
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= s; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if (j >= arr[i - 1])
            {
                dp[i][j] = dp[i][j] || dp[i - 1][j - arr[i - 1]];
            }
        }
    }
    return dp[n][s];
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n, s;
        cin >> n >> s;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        if (solve(arr, 0, 0, n, s))
        {
            cout << "YES";
        }
        else
        {
            cout << "NO";
        }
        cout << "\n";
    }
}