#include <iostream>
using namespace std;

void solve(long long x) {
    long long mx = 5;
    long long cnt = 0;
    while ((x/mx)> 0) {
        cnt += (x/mx);
        mx *= 5;
    }
    cout << cnt << "\n";
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        long long x;
        cin >> x;
        solve(x);
    }
}