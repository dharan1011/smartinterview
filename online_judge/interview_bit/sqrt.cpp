using ll = long long;
ll pwr(ll a, ll b){
    ll res = 1;
    while (b)
    {
        if(b&1){
            res *= a;
        }
        b >>= 1;
        a *= a;
    }
    return res;
}
int sqrt(int A) {
    if(A == 0){
        return 0;
    }
    int lo = 1;
    int hi = A/2;
    while (lo < hi)
    {
        int mid = lo + (hi - lo + 1) / 2;
        ll sq = pwr(mid, 2);
        if(sq > A){
            hi = mid - 1;
        }else{
            lo = mid;
        }
    }
    return lo;
}
