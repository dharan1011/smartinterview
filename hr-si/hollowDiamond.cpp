#include <iostream>
using namespace std;

int ithOdd(int i) {
    return 2 * i - 1;
}

void solve(int n) {
    int h = n / 2;
    for (int i = 0; i <= h; i++) {
        for (int j = 0; j < h - i; j++)
            cout << " ";
        if (i == 0) {
            cout << "*";
        }
        else {
            cout << "*";
            for (int j = 0; j < ithOdd(i); j++)
                cout << " ";
            cout << "*";
        }
        cout << "\n";
    }
    for (int i = h-1; i >= 0; --i) {
        for (int j = 0; j < h - i; j++)
            cout << " ";
        if (i == 0) {
            cout << "*";
        }
        else {
            cout << "*";
            for (int j = 0; j < ithOdd(i); j++)
                cout << " ";
            cout << "*";
        }
        cout << "\n";
    }
}

int main() {
    int T, x;
    cin >> T;
    for (int c = 1; c <= T; c++) {
        cin >> x;
        cout << "Case #" << c << ":" << '\n';
        solve(x);
    }
}