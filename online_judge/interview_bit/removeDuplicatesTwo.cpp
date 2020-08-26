#include <vector>
using namespace std;
int removeDuplicates(vector<int> &A) {
    int n = A.size();
    if(n <= 2){
        return n;
    }
    int cnt = 0;
    if(A[0] == A[1]){
        cnt = 2;
    }else{
        cnt = 1;
    }
    int lo = 1;
    for(int i = 2; i < n; i++){
        if(A[i] == A[lo] && cnt == 1){
            cnt++;
            lo++;
            swap(A[i],A[lo]);
        }else if(A[i] != A[lo]){
            lo++;
            swap(A[i],A[lo]);
            cnt = 1;
        }
    }
    return lo + 1;
}

// 1,1,1,2,2
