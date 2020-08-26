#include <vector>
using namespace std;
int removeElement(vector<int> &A, int B) {
    int lo = 0;
    int n = A.size();
    for(int i = 0; i < n; i++){
        if(A[i] != B){
            swap(A[i],A[lo]);
            lo++;
        }
    }
    return lo;
}