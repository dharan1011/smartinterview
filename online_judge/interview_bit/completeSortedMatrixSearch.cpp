#include <vector>
using namespace std;

int searchMatrix(vector<vector<int> > &A, int B) {
    int n = A.size(); // rows
    int m = A[0].size(); // cols
    int hi = (n * m) - 1;
    int lo = 0;
    while(lo <= hi){
        int mid = lo + (hi - lo) / 2;
        int r = mid / m; // 2d axis row
        int c = mid % m; // 2d axis col
        if(A[r][c] == B){
            return 1;
        }
        if(A[r][c] > B){
            hi = mid - 1;
        }else{
            lo = mid + 1;
        }
    }
    return 0;
}
