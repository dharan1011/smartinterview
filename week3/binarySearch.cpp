#include <iostream>
#include <vector>
#include <climits>
using namespace std;

bool binary_search(vector<int> &arr, int key){
    int lo = 0;
    int hi = arr.size() - 1;
    while (lo <= hi)
    {
        int mid = lo + (hi - lo)/2;
        if(arr[mid] == key){
            return true;
        }
        if(key > arr[mid]){ // key lies to right of mid so we discard all the element to left of mid
            lo = mid + 1;
        }else{
            hi = mid + 1;
        }
    }
    return false;
}

bool binary_search_rec(vector<int> &arr, int key, int lo, int hi){
    if(lo <= hi){
        int mid = lo + (hi - lo) / 2;
        if(arr[mid] == key) return true;
        if(key > arr[mid]){
            return binary_search_rec(arr, key, mid + 1, hi);
        }else{
            return binary_search_rec(arr, key, lo, mid - 1);
        }
    }
    return false;
}

// binary search recursive
int bsr(vector<int> &arr, int lo, int hi, int key){
    if(lo > hi){
        return -1;
    }
    int mid = lo + (hi - lo) / 2;
    if(arr[mid] == key){
        return mid;
    }
    if(key > arr[mid]){
        return bsr(arr,mid+1,hi,key);
    }
    return bsr(arr,lo,mid-1,key);
}

// binary search iterative
int bsi(vector<int> &arr, int key){
    int lo = 0;
    int hi = arr.size() - 1;
    while(lo <= hi){
        int mid = lo + (hi - lo) / 2;
        if(arr[mid] == key){
            return mid;
        }
        if(key > arr[mid]){
            lo = mid + 1;
        }else{
            hi = mid - 1;
        }
    }
    return -1;
}

int floor(vector<int> &arr, int x){
    int res = INT_MIN;
    int lo = 0;
    int hi = arr.size() - 1;
    while(lo <= hi){
        int mid = lo + (hi - lo) / 2;
        if(arr[mid] <= x){
            res = arr[mid];
            lo = mid + 1;
        }else{
            hi = mid - 1;
        }
    }
    return res;
}

int first_index(vector<int> &arr, int x){
    int res = -1;
    int lo = 0;
    int hi = arr.size() - 1;
    while(lo <= hi){
        int mid = lo + (hi - lo) / 2;
        if(arr[mid] >= x){
            res = mid;
            hi = mid - 1;
        }else{
            lo = mid + 1;
        }
    }
    return res;
}

int last_index(vector<int> &arr, int x){
    int res = -1;
    int lo = 0;
    int hi = arr.size() - 1;
    while(lo <= hi){
        int mid = lo + (hi - lo) / 2;
        if(arr[mid] <= x){
            res = arr[mid];
            lo = mid + 1;
        }else{
            hi = mid - 1;
        }
    }
    return res;
}

/*
binary search on even index only
IP : Compressed array and of size 2n
*/
void binary_search_even_index(vector<int> &arr, int target){
    int n = arr.size();
    int lo = 0;
    int hi = n - 2;
    /*
    0 2 4 6 8 10 12 14  
    */
   while(lo <= hi){
       int mid = (lo + hi)/2;
       if(mid&1) mid--;
       if(arr[mid] == target){
           /*
           Compute
           */
       }
       if(target > arr[mid]){
           lo = mid + 2;
       }else{
           hi = mid - 2;
       }
   }
}

int clower_bound(vector<int> &arr, int target){
    // returns index of first element <= target
    int lo = 0;
    int hi = arr.size();
    while (lo < hi)
    {
        int mid = lo + (hi - lo) / 2;
        if(target <= arr[mid]){
            hi = mid;
        }else{
            lo = mid + 1;
        }
    }
    return hi;
}

int cupper_bound(vector<int> &arr, int target){
    int lo = 0;
    int hi = arr.size() - 1;
    while (lo <  hi)
    {
        int mid;
        if(target >= arr[mid]){
            lo = mid;
        }else{
            hi = mid - 1;
        }
    }
    return lo;
}


int main(){

    vector<int> arr {1,2,3,3,3,6,7};
    cout << clower_bound(arr, 0) << "\n";
    return 0;
}