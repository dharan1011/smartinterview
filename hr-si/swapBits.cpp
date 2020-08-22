#include <iostream>
#define fast                    \
    cin.sync_with_stdio(false); \
    cin.tie(NULL);              \
    cout.tie(NULL);
using namespace std;

void solve(unsigned int &num)
{
    unsigned int c, n, one = 1;
    for (int i = 0; i < 32; i += 2)
    {
        c = ((num >> i) & one);
        n = ((num >> (i + 1)) & one);
        if (c != n)
        {
            num = (num ^ (one << i));
            num = (num ^ (one << (i + 1)));
        }
    }
}

int main()
{
    fast int T;
    cin >> T;
    while (T--)
    {
        unsigned int x;
        cin >> x;
        solve(x);
        cout << x << "\n";
    }
}