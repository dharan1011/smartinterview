#include <iostream>
#include <vector>
using namespace std;

vector<int> twoSumBruteForce(vector<int>& numbers, int target){
    int n = numbers.size();
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(numbers[i]+numbers[j] == target){
                return {i+1,j+1};
            }
        }
    }
    return {};
}


// i/p array must be sorted
/*
Notes : 
    When we discard a element this inc/dec a pointer that means
    all elemenets which are left to inc pointer or right of increment pointer
    with pair with element at other pointer whoes sum > or < target sum.
*/
vector<int> twoSum(vector<int>& numbers, int target) {
    int lo = 0;
    int hi = numbers.size() - 1;
    while(lo < hi){
        int sum = numbers[lo] + numbers[hi];
        if(sum == target){
            break;
        }
        if(sum < target){
            lo++;
        }else{
            hi--;
        }
    }
    return {lo+1, hi+1};
}


