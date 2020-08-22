#include <iostream>
using namespace std;

int arr[10005];

void solve(int n) {
    int numsxor = 0;
    for (int i = 1; i <= n+1; i++)
        numsxor ^= i;
    int arrxor = 0;
    for (int i = 0; i < n; i++) {
        arrxor ^= arr[i];
    }
    cout << (numsxor ^ arrxor) << "\n";
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        solve(n);
    }
}