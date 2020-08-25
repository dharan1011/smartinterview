#include <vector>
using namespace std;
void merge(vector<int> &A, vector<int> &B) {
    int n = A.size();
    int m = B.size();
    A.resize(n+m);
    int posA = n - 1;
    int posB = m - 1;
    int posC = m + n - 1;
    while (posA >= 0 && posB >= 0)
    {
        if(A[posA] > B[posB]){
            A[posC--] = A[posA--];
        }else{
            A[posC--] = B[posB--];
        }
    }
    while (posC >= 0 && posB >= 0)
    {
        A[posC--] = B[posB--];
    }
    
}
