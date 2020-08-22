#include <iostream>
using namespace std;
int main() {
    int T;
    cin >> T;
    long long x;
    while (T--) {
        cin >> x;
        if (x&(x-1)) {
            cout << "False";
        }
        else {
            cout << "True";
        }
        cout << "\n";
    }
}