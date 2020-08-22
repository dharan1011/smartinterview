#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#define fast cin.sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

/*
    a <= arr[i] <= b
    lo = a
    map first element of range to 0 by
    arr[i] - a 
    retrive original number by 
    arr[i] + a
*/

void solve(vector<int> &arr){
    vector<pair<int,int>> ft(2001);
    int lo = -1000;
    int n = arr.size();
    for(int i = 0; i < n; i++){
        int idx = arr[i] - lo;
        ft[idx].first++;
        ft[idx].second = arr[i];
    }
    sort(ft.begin(), ft.end());
    for(int i = 0; i < 2001; i++){
        if(ft[i].first > 0){
            for(int j = 0; j < ft[i].first; j++)
                cout << ft[i].second << " ";
        }
    }
    cout << "\n";
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
    }
    return 0;
}