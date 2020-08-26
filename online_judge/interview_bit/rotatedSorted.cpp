#include <vector>
using namespace std;

int findPeak(const vector<int> &A){
    int lo = 0;
    int hi = A.size() - 1;
    if(A[lo] <= A[hi]){
        return hi;
    }
    while (lo < hi)
    {
        int mid = lo + (hi - lo) / 2;
        if(A[mid] > A[mid + 1]){
            return mid;
        }
        if(A[lo] < A[mid]){
            lo = mid + 1;
        }else if(A[mid] < A[lo]){
            hi = mid;
        }
    }
    return lo;
}
int bs(const vector<int> &A, int lo, int hi, int target){
    while (lo < hi)
    {
        int mid = lo + (hi - lo + 1) / 2;
        if(A[mid] > target){
            hi = mid - 1;
        }else{
            lo = mid;
        }
    }
    
    return A[lo] == target ? lo : - 1;
}
int search(const vector<int> &A, int B) {
    int piv = findPeak(A);
    int r1 = bs(A,0,piv,B);
    if(r1 != -1){
        return r1;
    }
    return bs(A,piv+1,A.size()-1,B);
}