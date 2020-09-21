#include <bits/stdc++.h>
using namespace std;
#define fast cin.sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
class sqrt_decomposition{
 
 
    int _bi(int idx) {
        return idx / b;
    }
 
    int _bi_e(int bi) {
        return (bi+1)*b-1;
    }
    int _bi_s(int bi) {
        return bi * b;
    }
 
//    void update_block(int bi){
//        int l = _bi_e(bi);
//        int r = _bi_s(bi);
//        block[bi].clear();
//        for(int i = l; i <= r; i++){
//            block[bi].push_back(arr[i]);
//        }
//        sort(block[bi].begin(), block[bi].end());
//    }
 
    int bs(vector<int> &arr, int x){
        if(arr.empty()) return 0;
        int lo = 0;
        int hi = (int) arr.size() - 1;
        while(lo < hi){
            int mid = lo + (hi - lo) / 2;
            if(arr[mid] < x){
                lo = mid + 1;
            }else{
                hi = mid;
            }
        }
        return (arr[lo] >= x) ? (int) arr.size() - lo : 0;
    }
 
    void pre_process(){
        for(int i = 0; i < n; i++){
            block[_bi(i)].push_back(arr[i]);
        }
        for(int i = 0; i < b; i++){
            sort(block[i].begin(), block[i].end()); // sqrt(n)*sqrt(n)*log(sqrt(n)) -> Nlog(sqrt(n))
        }
    }
 
public:
    vector<int> *block;
    vector<int> arr {};
    int n;
    int b;
    sqrt_decomposition(vector<int> iarr){
        n = iarr.size();
        b = (int) sqrt(n+.0) + 1;
        block = new vector<int>[b];
        arr = vector<int>(iarr.begin(), iarr.end());
        pre_process();
    }
 
    void point_update(int i, int x){
        int bi = _bi(i);
        arr[i] = x; // update new value in original array
        block[bi].clear();
        for(int s = _bi_s(bi); s <= _bi_e(bi); s++){
            block[bi].push_back(arr[s]);
        }
        sort(block[bi].begin(), block[bi].end()); // sort the array
    }
 
    int range_query(int l, int r, int c) {
        int cnt = 0;
        int bi_l = _bi(l);
        int bi_r = _bi(r);
        vector<int> temp;
        if(bi_l == bi_r){
            for(int i = l; i <= r; i++){
                temp.push_back(arr[i]);
            }
            sort(temp.begin(), temp.end());
            cnt += bs(temp, c);
            return cnt;
        }
        for(int i = l, end = _bi_e(bi_l); i <= end; i++){
            temp.push_back(arr[i]);
        }
        sort(temp.begin(), temp.end());
        cnt += bs(temp, c);
        for(int i = bi_l + 1; i <= bi_r - 1; i++){
            cnt += bs(block[i], c);
        }
        temp = {};
        for(int i = _bi_s(bi_r); i <= r; i++){
            temp.push_back(arr[i]);
        }
        sort(temp.begin(), temp.end());
        cnt += bs(temp, c);
        return cnt;
    }
};
 
int main() {
    fast
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    sqrt_decomposition sd(arr);
    int q;
    cin >> q;
    while(q--){
        int t;
        cin >> t;
        if(t == 0){
            int a,b,c;
            cin >> a >> b >> c;
            a--;
            b--;
            cout << sd.range_query(a,b,c) << "\n";
        }else{
            int a, b;
            cin >> a >> b;
            a--;
            sd.point_update(a, b);
        }
    }
    return 0;
}
