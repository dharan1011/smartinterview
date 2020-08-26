#include <vector>
#include <utility>
#include <algorithm>
using namespace  std;

vector<int> two_sum(vector<int>& arr, int lo, int hi, int target){
    while (lo < hi)
    {
        int sum = arr[lo] + arr[hi];
        if(sum == target){
            return {lo, hi};
        }
        if(sum > target){
            hi--;
        }else{
            lo++;
        }
    }
    
    return {};
}

/*
a + b + c = 0
-a = b + c
*/

vector<vector<int> > threeSum(vector<int> &A) {
    vector<vector<int>> res;
    sort(A.begin(), A.end());
    int n = A.size();
    for(int i = n - 1; i >= 2; --i){
        int ntf = -A[i];
        auto res = two_sum(A,0,i-1,ntf);
        if(!res.empty()){
            vector<int> tr;
            tr.push_back(res[0]);
            tr.push_back(res[1]);
            tr.push_back(ntf);
            res.emplace({res[0],res[1],ntf});
        }
    }
    return res;
}
