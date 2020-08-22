#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// https://leetcode.com/problems/binary-search/discuss/423162/Binary-Search-101-The-Ultimate-Binary-Search-Handbook
// https://leetcode.com/discuss/general-discussion/786126/python-powerful-ultimate-binary-search-template-solved-many-problems

/*
Minimize k s.t condition(k) is True
*/

bool condition(int k){
    /*
    compute
    */
   return true;
}

int binary_search(vector<int> &arr){
    int lo = *min_element(arr.begin(), arr.end());
    int hi = *max_element(arr.begin(), arr.end());
    while(lo < hi){
        int mid = lo + (hi - lo) / 2;
        if(condition(mid)){
            hi = mid;
        }else{
            lo = mid + 1;
        }
    }
}

/*
Where to use Binary Search ?
If we can discover some kind of monotonicity, for example, if condition(k) is True then condition(k + 1) is True, then we can consider binary search.
*/