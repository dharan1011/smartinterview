#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
void solve(ll num) {
    if(num == 0){
        cout << 0 << '\n';
        return;
    }
    string res = "";
    while (num > 0) {
        if (num & 1) {
            res += '1';
        }
        else {
            res += '0';
        }
        num >>= 1;
    }
    reverse(res.begin(), res.end());
    cout << res << "\n";
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        ll num;
        cin >> num;
        solve(num);
    }
}