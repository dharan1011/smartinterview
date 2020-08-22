#include <iostream>
#include <vector>
using namespace std;
/*
 * To use 31 or 63 bit use unsing unsigned int or long
 * */

int pow(int N){
    if(N >= 31){
        return -1; // Interger Overflow
    }
    return 1 << N;
}

int pow(int a, int b){
    int res = 1;
    int mod = 1e9 + 7;
    a = a%mod;
    for(int i = 1; i <= b; i++){
        res = (res * a) % mod;
    }
    return res;
}

long long powl (int N){
    if(N >= 63){
        return -1;
    }
    return 1LL << N;
}

/*
 * Data Type    MSB
 * int          31
 * long long    63
 * uint         31
 * ulong long   63
 * */

// Set bits at pos a and b.  0 <= (a,b) <= 25
int solve(int a, int b){
    return (1 << a) | (1 << b);
}

// check set bit at pos i.  0 <= i <= 30
bool check(int n, int i){
    return n & (1 << i); // (n >> i) > 0
}

int count(int n){
    int c = 0;
    while(n){
        n = n & (n - 1);
        c++;
    }
    return c;
}

vector<int> divisors(int n){
    vector<int> res;
    for(int i = 1; i*i <= n; i++){
        if(n%i == 0){
            res.push_back(i);
            res.push_back(n/i);
        }
    }
    return res;
}


int main(){
    return 0;
}
