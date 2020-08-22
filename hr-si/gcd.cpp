#include <iostream>
using namespace std;
typedef long long ll;
/*
wkt lcm * gcd = a * b
*/

void swap(int &a, int &b) {
    int t = a;
    a = b;
    b = t;
}

int gcd(int a, int b) {
    if (b > a) {
        swap(a, b);
    }
    while ((a%b) != 0) {
        int c = a % b;
        a = b;
        b = c;
    }
    return b;
}

ll lcm(ll a, ll b, int gc) {
    return (a * b)/ gc;
}

int main() {
    int a, b;
    int T;
    cin >> T;
    while (T--) {
        cin >> a >> b;
        int g = gcd(a, b);
        cout << lcm(a, b, g) << " " << g << "\n";
    }
}