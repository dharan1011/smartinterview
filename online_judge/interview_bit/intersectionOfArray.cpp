#include <vector>
using namespace std;
vector<int> intersect(const vector<int> &A, const vector<int> &B) {
    vector<int> C;
    int n = A.size(), m = B.size();
    C.reserve(n+m);
    int posA = 0;
    int posB = 0;
    while (posA < n && posB < m)
    {
        if(A[posA] < B[posB]){
            posA++;
        }else if(A[posA] > B[posB]){
            posB++;
        }else{
            C.push_back(A[posA]);
            posA++;
            posB++;
        }
    }
    return C;
}
