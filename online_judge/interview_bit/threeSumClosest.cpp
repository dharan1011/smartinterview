#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int two_sum(vector<int>& arr, int lo, int hi, int target){
    while (lo < hi)
    {
        int sum = arr[lo] + arr[hi];
        if(sum == target){
            return true;
        }
        if(sum > target){
            hi--;
        }else{
            lo++;
        }
    }
    
    return false;
}

int threeSumClosest(vector<int> &A, int B) {
    int n = A.size();
    int diff = INT_MAX;
    int res;
    sort(A.begin(), A.end());
    for(int i = 0; i < n; i++){
        int a = A[i];
        for(int j = i + 1; j < n; j++){
            int b = A[j];
            for(int k = j + 1; k < n; k++){
                int c = A[k];
                int sum = a + b + c;
                int cdiff = abs(sum - B);
                if(cdiff < diff){
                    diff = cdiff;
                    res = sum;
                }
            }
        }
    }
    return res;
}
