#include <iostream>
using namespace std;
/*
 *
 * This problem has three approaches
 * 1) Recusion
 * 2) generate all subset using bits and sum each subset and check for k
 * 3) DP
 * */
int subsetSum(int arr[], int n, int k){
    int subsetSize = 1LL << n;
    for(int  i = 0; i < subsetSize; i++){
        int sum = 0;
        int j = 0;
        int currNum = i;
        while(currNum > 0){
            if(currNum & 1){
                sum += arr[j];
            }
            j++;
            currNum >>= 1;
        }
        if(sum == k){
            return true;    
        }
    }
    return false;
}
int main(){
    return 0;
}
