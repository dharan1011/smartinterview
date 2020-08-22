#include <iostream>
#include <vector>
#include <algorithm>
#define fast cin.sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

bool feasible(vector<int>& tasks, int threshold, int k){
    int timeTaken = 0;
    int w = 1;
    int n = tasks.size();
    for(int i = 0; i < n; i++){
        timeTaken += tasks[i];
        if(timeTaken > threshold){ // time taken is greater than threshold
            timeTaken = tasks[i]; // reset time to current task
            if(timeTaken > threshold){
                return false;
            }
            w++; // add a worker
            if(w > k){
                return false;
            }
        }
    }
    return true;
}
// minimize res
void solve(vector<int>& tasks, int k, int maxTime){
    int lo = 1; // atleast it will take max time of the tasks
    int hi = maxTime;
    while (lo < hi)
    {
        int mid = lo + (hi - lo) / 2; // baised to left
        if(feasible(tasks, mid, k)){
            hi = mid; // consider this value
        }else{ // if cannot do
            lo = mid + 1; // increase the time
        }
    }
    cout << lo << "\n";
}

int main(){
    fast
    int T;
    cin >> T;
    while(T--){
        int n, k, sum = 0;
        cin >> n >> k;
        vector<int> arr(n);
        for(int i = 0; i < n; i++){
            cin >> arr[i];
            sum += arr[i];
        }
        solve(arr, k, sum);
    }
    return 0;
}


// https://pastebin.com/pswP56V2