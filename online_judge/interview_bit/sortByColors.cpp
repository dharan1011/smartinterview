#include <vector>
#include <algorithm>
using namespace std;

void sortColors(vector<int> &A) {
    int n = A.size();
    int lo = 0, mid = 0, hi = n-1;
    while(mid <= hi){
        if(A[mid] == 0){
            swap(A[lo],A[mid]);
            lo++;
            mid++;
        }else if(A[mid] == 1){
            mid++;
        }else{
            swap(A[mid],A[hi]);
            hi--;
        }
    }
}

/*
 0, 1, 2, 0, 1, 2
 
*/