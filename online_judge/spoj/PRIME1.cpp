#include <iostream>
#include <vector>
#include <cmath>
#define fast cin.sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
using ll = long long;

const int MAX_N = 1e5 + 1;
vector<int> primes;

void generate(){
    primes.reserve(MAX_N);
    vector<bool> check(MAX_N+1, true);
    // check[0] = check[1] = false;
    for(ll i = 2; i <= MAX_N; i++){
        if(check[i]){
            primes.push_back(i);
            for(ll j = i * i; j <= MAX_N; j += i){
                if(check[j]){
                    check[j] = false;
                }
            }
        }
    }
}

void solve(int a, int b){
    vector<bool> check(b-a+1, true);
    for(ll x : primes){
        if(x * x > b) break;
        for(ll j = x * x; j <= b; j += x){
            if(j >= a){
                int idx = j - a;
                if(check[idx]){
                    check[idx] = false;
                }
            }
        }
    }
    for(int i = 0; i < check.size(); i++){
        if(a + i == 1) continue;
        if(check[i]){
            cout << a + i << "\n";
        }
    }
    cout << "\n";
}

int main(){
    fast
    generate();
    int t, a, b;
    cin >> t;
    while(t--){
        cin >> a >> b;
        solve(a, b);
    }
}