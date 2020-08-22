#include <iostream>
using namespace std;

typedef long long ll;
/*
a^b = a^b/2 * a^b/2  if b is even
a^b = a * a^b/2 * a^b/2  if b is odd
*/
ll pwr(int a, int b)
{
    if (b == 0)
    {
        return 1; // anything power zero is 1
    }

    int p = pwr(a, b / 2);

    if (b & 1)
    {
        return a * p * p;
    }

    return p * p;
}

/*
(a*b) = ((a%mod) * (b*mod))%mod
*/

ll be(ll a, ll b, int mod)
{
    ll res = 1;
    a = a % mod;
    while (b)
    {
        if (b & 1)
        {
            res = (res * a) % mod;
        }
        b >>= 1;
        a = (a * a) % mod; // a ^ 2 = (a^1 * a^1) % mod => (a^1%mod * a^1%mod) % mod
    }
    return res;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int a, b;
        cin >> a >> b;
        cout << be(a, b, 1e9+7) << "\n";
    }
}