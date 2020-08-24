/*
    tags : Binary Search
*/

#include <vector>
#include <algorithm>
using namespace std;

bool isFallingSlope(const int &a, const int &b){
    return a > b;
}

int findPeakElement(vector<int>& nums){
    int lo = 0;
    int hi = nums.size() - 1;
    while(lo < hi){
        int mid = lo + (hi - lo) / 2;
        if(isFallingSlope(nums[mid], nums[mid+1])){
            hi = mid;
        }else{
            lo = mid + 1;
        }
    }
    return lo;
}