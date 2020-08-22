#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define rep(i,n)        for (i = 0; i < n; ++i)
#define REP(i,k,n)      for (i = k; i <= n; ++i)
#define REPR(i,k,n)     for (i = k; i >= n; --i)
#define w(x)            int x; cin>>x; while(x--)
#define mk(arr,n,type)  type *arr=new type[n];
#define inrange(i, a, b)((i >= min(a, b)) && (i <= max(a, b)))
#define fast            ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define fsb(index)      (index & -index)
typedef long long       ll;
typedef pair<int,int>   pi;
typedef pair<long,long> pl;
typedef vector<int>     vi;
typedef vector<pi>      vpi;
typedef vector<pl>      vpl;
typedef vector<vi>      vvi;
typedef tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
const int mod = 1000000007;


const int N = 1e6 + 1;
int arr[N];

int findNextFarthest(int lo, int hi, int x){
    int res = -1;
    while (lo <= hi)
    {
        int mid = lo + (hi - lo) / 2;
        if(arr[mid] >= x){
            res = mid;
            hi = mid - 1;
        }else{
            lo = mid + 1;
        }
    }
    return res;
}

bool feasible(int distance, int c, int n){
    int i = 0;
    int cc = 1;
    while(i < n){
        int next = arr[i] + distance;
        int ni = findNextFarthest(i+1,n-1,next);
        if(ni != -1){
            i = ni;
            cc++;
        }else{
            break;
        }
    }
    return cc >= c;
}
// maximizes res
void solve(int n, int c){
    sort(arr, arr+n);
    int hi = arr[n-1] - arr[0];
    int lo = arr[1] - arr[0];
    while (lo < hi)
    {
        int mid = lo + (hi - lo + 1) / 2; // right biased
        if(feasible(mid, c, n)){
            lo = mid;
        }else{
            hi = mid - 1;
        }
    }
    cout << lo << "\n";
}

int main() {
    fast
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    w(t){
        int n, k;
        cin >> n >> k;
        int i;
        rep(i, n) cin >> arr[i];
        solve(n, k);
    }
    return 0;
}

/*
1 2 4 8 9

lo = 1, hi = 8
mid = 3
*/