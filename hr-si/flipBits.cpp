#include <iostream>
#define fast                    \
    cin.sync_with_stdio(false); \
    cin.tie(NULL);
using namespace std;

void solve(unsigned int a, unsigned int b)
{
    unsigned int diff = a ^ b;
    int cnt = 0;
    while (diff)
    {
        cnt++;
        diff &= (diff - 1);
    }
    cout << diff << '\n';
}

int main()
{
    fast int T;
    cin >> T;
    while (T--)
    {
        unsigned int a, b;
        cin >> a >> b;
        solve(a, b);
    }
}