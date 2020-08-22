#include <iostream>
using namespace std;
const int N = 1e4 + 5;
unsigned int arr[N];

void solve(int n)
{
    unsigned int res = 0, one = 1;
    for (int i = 0; i < 32; i++)
    {
        int cnt = 0;
        for (int j = 0; j < n; j++)
        {
            if (arr[j] & (one << i))
            {
                cnt++;
            }
        }
        if (cnt % 3)
        {
            res |= (one << i);
        }
    }
    cout << res << '\n';
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        solve(n);
    }
}