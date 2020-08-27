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

vector<vector<int>> threeSum(vector<int> &A) {
    vector<vector<int>> res;
    
    return res;
}
