#include <iostream>
#include <unordered_map>
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
using namespace std;
const int mod = 1e9 + 7;
typedef long long ll;
unordered_map<int, ll> memo;

void fact(int n)
{
    // if (memo.find(n) != memo.end())
    // {
    //     return memo[n];
    // }
    // memo[n] = ((n % mod) * fact(n - 1)) % mod;
    // return memo[n];
    for (int i = 2; i <= n; i++)
        memo[i] = ((i % mod) * memo[i - 1]) % mod;
}

int main()
{
    fast
        memo[0] = memo[1] = 1ll % mod;
    fact(1000000);
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        cout << memo[n] << "\n";
    }
}