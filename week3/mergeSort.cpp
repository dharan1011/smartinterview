#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int inversion_count = 0;

void _merge(vector<int> &arr, int low, int mid, int high){
    int n1 = mid - low + 1;
    int n2 = high - mid;
    vector<int> A(n1), B(n2);
    for(int i = 0; i < n1; i++){
        A[i] = arr[low + i];
    }
    for(int i = 0; i < n2; i++){
        B[i] = arr[mid + i + 1];
    }
    
    int index = low;
    int p1 = 0, p2 = 0;
    while(p1 < n1 && p2 < n2){
        if(A[p1] <= B[p2]){
            arr[index++] = A[p1++];
        }else{
            /*
            Inversion Count
            count += (n1 - p1);
            */
           inversion_count += (n1 - p1);
            arr[index++] = B[p2++];
        }
    }
    while(p1 < n1){
        arr[index++] = A[p1++];
    }
    while(p2 < n2){
        arr[index++] = B[p2++];
    }
}

void _merge_sort(vector<int> &arr, int low, int high){
    if(high == low){
        return;
    }
    int mid = low + (high - low) / 2;
    _merge_sort(arr, low, mid);
    _merge_sort(arr, mid + 1, high);
    _merge(arr, low, mid, high);
}

void merge_sort(vector<int> &arr){
    inversion_count = 0;
    _merge_sort(arr,0,arr.size()-1);
}


int main(){
    vector<int> arr = {3,10,8,2,7,-5,15,8,1,12};
    merge_sort(arr);
    cout << "Inversion Count " << inversion_count;
}