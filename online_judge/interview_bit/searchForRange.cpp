#include <vector>
using namespace std;

int bss(const vector<int> &arr, int target){
    int lo = 0;
    int hi = arr.size() - 1;
    while (lo < hi)
    {
        int mid = lo + (hi - lo) / 2;
        if(arr[mid] < target){
            lo = mid + 1;
        }else{
            hi = mid;
        }
    }
    return arr[lo] == target ? lo : -1;
}

int bse(const vector<int> &arr, int target){
    int lo = 0;
    int hi = arr.size() - 1;
    while (lo < hi)
    {
        int mid = lo + (hi - lo + 1) / 2;
        if(arr[mid] > target){
            hi = mid - 1;
        }else{
            lo = mid;
        }
    }
    return arr[lo] == target ? lo : -1;
}

vector<int> searchRange(const vector<int> &A, int B) {
    int start = bss(A,B);
    int end = bse(A,B);
    if(start == -1 || end == -1 || start > end){
        return {-1,-1};
    }
    return {start, end};
}
