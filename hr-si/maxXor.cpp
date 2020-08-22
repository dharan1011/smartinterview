#include <iostream>
#include <vector>
using namespace std;
/*
12 15 9

1 1 0 0
1 1 1 1 *
0 1 0 1 * 
*/

void solve(vector<int> &arr, int n);

int main(){
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
}