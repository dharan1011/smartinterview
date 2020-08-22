#include <vector>
#include <cstdlib>
#include <algorithm>
#include <iostream>
using namespace std;

namespace dca {
    class sorting {
    private:
        vector<int> arr;
        long long inversion_count;
        void __merge_sort(vector<int> &arr, int lo, int hi);
        void __merge(vector<int> &arr, int lo, int mid, int hi);
        void __quick_sort(vector<int> &arr, int lo, int hi);
        int __partition(vector<int> &arr, int lo, int hi);
        void __generate_rand_data(int);
    public:
        void merge_sort(vector<int>&);
        void quick_sort(vector<int>&);
        void insertion_sort(vector<int>&);
        void selection_sort(vector<int>&);
        long long getInversionCount();
        void test_sorting();
};
}

void dca::sorting::__merge(vector<int> &arr, int lo, int mid, int hi){
    int n1 = mid - lo + 1;
    int n2 = hi - mid;
    vector<int> A(n1), B(n2);
    for(int i = 0; i < n1; i++)
        A[i] = arr[lo + i];
    for(int i = 0; i < n2; i++)
        B[i] = arr[mid + i + 1];
    int idx = lo;
    int posA = 0, posB = 0;
    while(posA < n1 && posB < n2){
        if(A[posA] <= B[posB]){
            arr[idx++] = A[posA++];
        }else{
            inversion_count += (n1 - posA); // > all the elements from [posA, n1) are > B[posB]
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

void dca::sorting::__merge_sort(vector<int> &arr, int lo, int hi){
    if(lo == hi){
        return;
    }
    int mid = lo + (hi - lo) / 2;
    __merge_sort(arr, lo, mid);
    __merge_sort(arr, mid + 1, hi);
    __merge(arr, lo, mid, hi);
}

long long dca::sorting::getInversionCount(){
    return inversion_count;
}

void dca::sorting::merge_sort(vector<int> &arr){
    inversion_count = 0;
    int lo = 0;
    int hi = arr.size() - 1;
    __merge_sort(arr, lo, hi);
}

void dca::sorting::insertion_sort(vector<int>& arr){
    int n = arr.size();
    for(int i = 1; i < n; i++){
        int key = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

void dca::sorting::selection_sort(vector<int>& arr){
    int n = arr.size();
    for(int i = 0; i < n; i++){
        int mi = i;
        for(int j = i + 1; j < n; j++){
            if(arr[j] < arr[mi]){
                mi = j;
            }
        }
        if(mi != i){
            swap(arr[i], arr[mi]);
        }
    }
}

int dca::sorting::__partition(vector<int> &arr, int lo, int hi){
    int key = arr[hi];
    int start = lo;
    for(int i = lo; i < hi; i++){
        if(arr[i] <= key){ // <= to maintain stability
            swap(arr[start++], arr[i]);
        }
    }
    swap(arr[start], arr[hi]);
    return start;
}

void dca::sorting::__quick_sort(vector<int> &arr, int lo, int hi){
    if(lo >= hi) return;
    int p = __partition(arr, lo, hi);
    __quick_sort(arr,lo,p-1);
    __quick_sort(arr,p+1,hi);
}

void dca::sorting::quick_sort(vector<int>& arr){
    int n = arr.size();
    int lo = 0;
    int hi = n - 1;
    __quick_sort(arr, lo, hi);
}

void dca::sorting::__generate_rand_data(int n){
    arr.reserve(n);
    for(int i = 0; i < n; i++)
        arr.push_back(rand());
}

void dca::sorting::test_sorting(){
    __generate_rand_data(1000);
    merge_sort(arr);
    if(is_sorted(arr.begin(), arr.end())){
        cout << "Merge Sort Pass" << "\n";
    }else{
        cout << "Merge Sort Fail" << "\n";
    }
    __generate_rand_data(1000);
    quick_sort(arr);
    if(is_sorted(arr.begin(), arr.end())){
        cout << "Quick Sort Pass" << "\n";
    }else{
        cout << "Quick Sort Fail" << "\n";
    }
    __generate_rand_data(500);
    insertion_sort(arr);
    if(is_sorted(arr.begin(), arr.end())){
        cout << "Insertion Sort Pass" << "\n";
    }else{
        cout << "Insertion Sort Fail" << "\n";
    }
    __generate_rand_data(500);
    selection_sort(arr);
    if(is_sorted(arr.begin(), arr.end())){
        cout << "Selection Sort Pass" << "\n";
    }else{
        cout << "Selection Sort Fail" << "\n";
    }
}