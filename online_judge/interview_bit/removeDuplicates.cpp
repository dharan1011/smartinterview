#include <vector>
using namespace std;
int removeDuplicates(vector<int> &A) {
    int n = A.size();
    int lo = 0;
    for(int i = 1; i < n; i++){
        if(A[i] != A[lo]){
            lo++;
            swap(A[i], A[lo]);
        }
    }
    return lo + 1;
}