#include <iostream>
#define fast cin.sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int mod = 1e9 + 7;

void solve(long long n){
    long long n_c = n;
    long long sum = 0;
    long long i;
    for(i = 1; n > 0; i++){
        n -= i;
        sum += i;
    }
    i--;
    long long res = (1LL << i);
    long long posb = i - 1 - (sum - n_c);
    res |= (1LL << posb);
    cout << (res % mod) << "\n";
}

int main(){
    fast
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        solve(n);
    }
    return 0;
}
/*
00000011 : 3    1

00000101 : 5    2
00000110 : 6    3

00001001 : 9    4
00001010 : 10   5
00001100 : 12   6

00010001 : 17   7
00010010 : 18   8
00010100 : 20   9
00011000 : 28   10

00100001 : 33   11
00100010 : 34   12
00100100 : 36   13
00101000 : 40   14
00110000 : 48   15

hint  : sum of n natural numbers
*/