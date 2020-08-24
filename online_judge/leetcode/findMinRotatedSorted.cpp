#include <vector>
#include <algorithm>
using namespace std;

bool isPivot(const int &a, const int &b){
    return a > b;
}

int findMin(vector<int>& nums) {
    if(nums.size() == 1){
        return nums[0];
    }
    int lo = 0;
    int hi = nums.size() - 1;
    if(nums[lo] < nums[hi]){
        return nums[lo];
    }
    while(lo < hi){
        int mid = lo + (hi - lo) / 2;
        if(isPivot(nums[mid], nums[mid+1])){
            return nums[mid+1];
        }
        if(nums[lo] <= nums[mid]){
            lo = mid + 1;
        }else{
            hi = mid - 1;
        }
    }
    return nums[lo+1];
}