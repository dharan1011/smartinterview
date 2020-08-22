#include <iostream>
using namespace std;

void solve(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < n - i; j++)
            cout << " ";
        for (int j = 0; j < i; j++)
            cout << "*";
        cout << "\n";
    }
}

int main() {
    int T, x;
    cin >> T;
    for (int c = 1; c <= T; c++) {
        cout << "Case #" << c << ":" << "\n";
        cin >> x;
        solve(x);
    }
}