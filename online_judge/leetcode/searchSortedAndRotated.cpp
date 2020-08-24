#include <vector>
#include <algorithm>
using namespace std;

bool isPivot(const int &a, const int &b){
    return a > b;
}

int findPivot(vector<int> &nums){
    int lo = 0;
    int hi = nums.size() - 1;
    if(nums[lo] < nums[hi]){
        return hi;
    }
    while(lo < hi){
        int mid = lo + (hi - lo) / 2;
        if(isPivot(nums[mid], nums[mid+1])){
            return mid;
        }
        if(nums[lo] <= nums[mid]){ // <= take ex [0,1] and work on it
            lo = mid + 1;
        }else if(nums[mid] < nums[hi]){
            hi = mid - 1;
        }
    }
    return lo;
}

int bs(vector<int> &nums, int lo, int hi, int target){
    while(lo <= hi){
        int mid = lo + (hi - lo) / 2;
        if(nums[mid] == target){
            return mid;
        }
        if(target > nums[mid]){
            lo = mid + 1;
        }else{
            hi = mid - 1;
        }
    }
    return -1;
}

int search(vector<int>& nums, int target) {
    int piv = findPivot(nums);
    int lo = 0, hi = nums.size() - 1;
    int idx = bs(nums, lo, piv, target);
    if(idx != -1){
        return idx;
    }
    return bs(nums, piv+1, hi, target);
}