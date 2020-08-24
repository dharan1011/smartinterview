#include <vector>
using namespace std;

int searchInsert(vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int lo = 0;
    int hi = A.size();
    while(lo < hi){
        int mid = lo + (hi - lo + 1) / 2;
        if(A[mid] > B){
            hi = mid - 1;
        }else{
            lo = mid;
        }
    }
    if(A[lo] == B){
        return lo;
    }
    if(A[lo] < B){
        return lo + 1;
    }else{
        return lo;
    }
}
