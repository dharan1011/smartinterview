let binarySearch = (nums: [number], target : number) : number => {
    let lo = 0, hi = nums.length - 1;
    while(lo < hi){
        let mid = lo + Math.floor((hi - lo + 1)) / 2;
        if(target < nums[mid]){
            hi = mid - 1; // hi is move to right by one, so mid should be biased towards right
        }else{
            // <=
            lo = mid;
        }
    }
    return nums[lo] == target ? lo : -1;
}

/**
 * 
let lo = 0;
let hi = 100;
let mid = lo + Math.floor((hi - lo + 1)) / 2; upper mid, use when we move hi i.e hi = mid - 1
let mid = lo + Math.floor((hi - lo )) / 2; lower mid, use when we move lo i.e lo = mid + 1
to understand better work out on array of size two

My rule of thumb when it comes to binary search:

Include ALL possible answers when initialize lo & hi
Don't overflow the mid calculation
Shrink boundary using a logic that will exclude mid, My rule of thumb is always use a logic that you can exclude mid
Avoid infinity loop by picking the correct mid and shrinking logic
Always think of the case when there are 2 elements left


if condition is met stay hi/lo = mid
else move always hi/lo = mid +- 1

low < high, terminate when low == high
at every iteration search space is atleast two
 * 
 */
