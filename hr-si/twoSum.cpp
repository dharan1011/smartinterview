#include <iostream>
#include <vector>
#include <algorithm>
#define fast cin.sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

void bruteForce(vector<int> &arr, int n, int target){
    bool flag = false;
    for(int i = 0; i < n; i++){ // N
        for(int j = i + 1; j < n; j++){ // N - i - 1
            if(arr[i] + arr[j] == target){
                flag = true;
                break;
            }
        }
        if(flag){
            break;
        }
    }// TC : N^2 SC : 1
    if(flag){
        cout << "True";
    }else{
        cout << "False";
    }
    cout << "\n";
}

void two_pointer(vector<int> &arr, int target){
    /*
        For this method to work the array need to be sorted
    */
    sort(arr.begin(), arr.end()); // NlogN
    int lo = 0;
    int hi = arr.size() - 1;
    bool flag = false;
    while(lo < hi){
        int cs = arr[lo] + arr[hi];
        if(cs == target){
            flag = true;
            break;
        }
        if(cs < target){
            /*
                all elements from [0,lo] (current lo) paired with arr[hi] will result to sum less that target, 
                we discard all these pairs and so move to greater integer i.e to right
            */
            lo++;
        }else{
            /*
                all element from [hi, n) when paired with arr[lo] will result to sum greater than target,
                we discard all those pairs and move to a lesser element i. to left
            */
            hi--;
        }
    } // N
    // TC : NlogN + N SC : 1
    if(flag){
        cout << "True";
    }else{
        cout << "False";
    }
    cout << "\n";
}

bool bs(vector<int> &arr, int lo, int hi, int key){
    while(lo <= hi){
        int mid = lo + (hi - lo) / 2;
        if(arr[mid] == key){
            return true;
        }
        if(key > arr[mid]){ // as array is sorted if key is > arr[mid] then it lie to right of mid so we dicard all the 
        // element to left of mid i.e we change search space
            lo = mid + 1;
        }else{
            hi = mid - 1;
        }
    }
    return false;
}

void linear_traversal_binary_search(vector<int> &arr, int target){
    sort(arr.begin(), arr.end()); // NlogN;
    int n = arr.size();
    bool flag = false;
    for(int i = 0; i < n; i++){ // N
        int a = arr[i];
        int b = target - a;
        /*
        a + b = target
        b = target - a
        */
       if(bs(arr,i+1,n-1, b)){ // logN
           flag = true;
           break;
       }
    } // TC : NlogN + NlogN SC : 1
    if(flag){
        cout << "True";
    }else{
        cout << "False";
    }
    cout << "\n";
}

int main(){
    fast
    int T;
    cin >> T;
    while(T--){
        int n, target;
        cin >> n >> target;
        vector<int> arr(n);
        for(int i = 0; i < n; i++)
            cin >> arr[i];
        linear_traversal_binary_search(arr,target);
    }
}