#include <iostream>
#include <vector>
#define fast cin.sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
typedef long long ll;

ll pwr(ll a, ll b){
    ll res = 1;
    while(b){
        if(b&1){
            res *= a;
        }
        b >>= 1;
        a *= a;
    }
    return res;
}

ll bs(ll lo, ll hi, ll x){
    while(lo <= hi){
        ll mid = lo + (hi - lo) / 2;
        ll p = pwr(mid, 3);
        if(p == x){
            return mid;
        }
        if(p > x){
            hi = mid - 1;
        }else{
            lo = mid + 1;
        }
    }
    return -1;
}

int main(){
    fast
    int T;
    cin >> T;
    ll lo = 1;
    ll hi = 1e6;
    while(T--){
        ll x;
        cin >> x;
        if(x < 0){
            cout << "-";
            x = -x;
        }
        cout << bs(lo,hi,x) << "\n";
    }
    return 0;
}