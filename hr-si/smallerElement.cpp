#include <iostream>
#include <vector>
#include <algorithm>
#define fast cin.sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

/*
i < j
arr[i] > arr[j]
*/

static long long inversion_count = 0;

void merge(vector<int>& arr, int lo, int mid, int hi){
    int n1 = mid - lo + 1;
    int n2 = hi - mid;
    vector<int> A(n1), B(n2);
    for(int i = 0; i < n1; i++)
        A[i] = arr[lo + i];
    for(int i = 0; i < n2; i++)
        B[i] = arr[mid + i + 1];
    int posA = 0, posB = 0;
    int idx = lo;
    while(posA < n1 && posB < n2){
        if(A[posA] <= B[posB]){
            arr[idx++] = A[posA++];
        }else{
            inversion_count += (n1 - posA);
            arr[idx++] = B[posB++];
        }
    }
    while(posA < n1){
        arr[idx++] = A[posA++];
    }
    while(posB < n2){
        arr[idx++] = B[posB++];
    }
}

void merge_sort(vector<int>& arr, int lo, int hi){
    if(lo == hi) return;
    int mid = lo + (hi - lo) / 2;
    merge_sort(arr,lo, mid);
    merge_sort(arr, mid+1, hi);
    merge(arr,lo,mid,hi);
}

void solve(vector<int>& arr, int n){
    inversion_count = 0;
    merge_sort(arr, 0, n-1);
    cout << inversion_count << "\n";
}

int main(){
    fast
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int i = 0; i < n; i++)
            cin >> arr[i];
        solve(arr, n);
    }
    return 0;
}