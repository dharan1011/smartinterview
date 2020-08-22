#include <iostream>
#define fast cin.sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

int bubbleSortSwapCount(int arr[], int n){
    int sc = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j],arr[j+1]);
                sc++;
            }
        }
    }
    return sc;
}

int main(){
    fast
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        int arr[n];
        for(int i = 0; i < n; i++)
            cin >> arr[i];
        cout << bubbleSortSwapCount(arr, n) << "\n";
    }
    return 0;
}