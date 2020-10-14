bool isSet(int a, int p){
    return a & (1 << p);
}

int Solution::cntBits(vector<int> &A) {
    const int mod = 1e9 + 7;
    int n = A.size();
    long long res = 0 % mod;
    for(int bit = 0; bit < 31; bit++){
        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(isSet(A[i],bit)){
                cnt++;
            }
        }
        res += ((long long)cnt * (n - cnt) * 2) % mod;
        if(res >= mod) res -= mod;
    }
    return res;
}

