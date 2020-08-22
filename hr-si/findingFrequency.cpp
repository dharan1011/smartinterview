#include <iostream>
#include <vector>
#include <algorithm>
#define fast cin.sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;


// IP : 1 1 1 5 5 10 10 10
// OP : 1 3 5 2 10 3

vector<int> compress(vector<int> &arr){
    int c = 1;
    int n = arr.size();
    vector<int> res;
    res.reserve(2*n);

    for(int i = 1; i < n; i++){
        if(arr[i] == arr[i-1]){
            c++;
        }else{
            res.push_back(arr[i-1]);
            res.push_back(c);
            c = 1;
        }
    }
    if(c){
        res.push_back(arr[n-1]);
        res.push_back(c);
    }
    return res;
}

int binary_search_even_index(vector<int> &arr, int target){
    int lo = 0;
    int hi = arr.size() - 2;
    while(lo <= hi){
        int mid = lo + (hi - lo) / 2;
        if(mid&1) mid--;
        if(arr[mid] == target){
            return arr[mid + 1];
        }
        if(target > arr[mid]){
            lo = mid + 2;
        }else{
            hi = mid - 2;
        }
    }
    return 0;
}

void solve(vector<int> &arr, int x){
    cout << binary_search_even_index(arr, x) << "\n";
}

int main(){
    fast
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr.begin(), arr.end());
    arr = compress(arr);
    int Q;
    cin >> Q;
    while(Q--){
        int x;
        cin >> x;
        solve(arr, x);
    }
    return 0;
}