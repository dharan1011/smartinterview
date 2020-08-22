#include <iostream>
#include <vector>
#include <algorithm>
#define fast cin.sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
typedef long long ll;
void bs(vector<ll> &arr, int k){
    sort(arr.begin(), arr.end());
    // a - b = k
    // a = k + b
    bool flag = false;
    int n = arr.size();
    for(int i = 0; i < n; i++){
        int b = arr[i];
        int a = k + b;
        if(binary_search(arr.begin()+i+1, arr.end(), a)){
            flag = true;
            break;
        }
    }
    if(flag){
        cout << "true";
    }else{
        cout << "false";
    }
    cout << "\n";
}

void two_pointer(vector<ll> &arr, int k){
    /*
        a - b = k
        we can re write as
        a + (-b) = k
    */
   sort(arr.begin(), arr.end());
   bool flag = false;

    int n = arr.size();
    int posA = 1;
    int posB = 0;
    while (posA < n && posB < n){
        int diff = arr[posA] - arr[posB];
        if(posA != posB && diff == k){
            flag =true;
            break;
        }
        if(diff < k){
            posA++;
        }else{
            posB++;
        }
    }
    
    if(flag){
        cout << "true";
    }else{
        cout << "false";
    }
    cout << "\n";
}

int main(){
    fast
    int T;
    cin >> T;
    while(T--){ 
        int n, k;
        cin >> n >> k;
        vector<ll> arr(n);
        for(int i =  0; i < n; i++){
            cin >> arr[i];
        }
        two_pointer(arr,k);
    }
    return 0;
}
