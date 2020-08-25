#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

using ll = long long;

bool feasible(vector<int>& arr, ll x, int A){
    int CA = 1;
    ll sum = 0;
    int n = arr.size();
    for(int i = 0; i < n; i++){
        sum += arr[i];
        if(sum > x){
            CA++;
            sum = arr[i];
            if(CA > A){
                return false;
            }
        }
    }
    return true;
}

int paint(int A, int B, vector<int> &C) {
    ll hi = accumulate(C.begin(), C.end(), 0ll);
    ll lo = *max_element(C.begin(), C.end());
    const int mod = 10000003;
    while (lo < hi)
    {
        ll mid = lo + (hi - lo) / 2;
        if(feasible(C, mid, A)){
            hi = mid;
        }else{
            lo = mid + 1;
        }
    }
    return (lo*B) % mod;
}