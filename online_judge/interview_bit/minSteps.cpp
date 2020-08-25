#include <vector>
#include <cmath>
using namespace std;

int minDist(int srcX, int srcY, int destX, int destY){
    return max(abs(destX - srcX),abs(destY - srcY));
}

int coverPoints(vector<int> &A, vector<int> &B) {
    int minSteps = 0;
    for(int i = 1; i < A.size(); i++){
        minSteps += minDist(A[i-1],B[i-1],A[i],B[i]);
    }
    return minSteps;
}