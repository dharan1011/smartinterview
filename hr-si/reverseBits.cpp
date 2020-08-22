#include <iostream>
#define fast                    \
    cin.sync_with_stdio(false); \
    cin.tie(NULL);
using namespace std;

unsigned int reverseBits(unsigned int num)
{
    unsigned int res = 0, one = 1;
    for (int i = 0; i < 32; i++)
    {
        if (num & (one << i))
        {
            res |= (one << (32 - i - 1));
        }
    }
    return res;
}

int main()
{
    fast int T;
    cin >> T;
    while (T--)
    {
        unsigned int x;
        cin >> x;
        cout << reverseBits(x) << "\n";
    }
}