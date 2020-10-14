#include <vector>
#include <iostream>
#include <climits>
#include <queue>
#include <cmath>
#define fast cin.sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
// Method #1
// void is(vector<int> &ar, int val){
//     ar.push_back(val);
//     // insertion logic
//     int n = ar.size();
//     int idx = n - 1; // current index
//     int key = ar[idx];
//     int j = idx - 1;
//     while(j >= 0 && ar[j] > key){
//         ar[j+1] = ar[j]; // move right
//         j--;
//     }
//     ar[j+1] = key;
// }

// void solve(vector<int> &ar, int n){
//     vector<int> car;
//     for(int i = 0; i < n; i++){
//         is(car, ar[i]);
//         int cn = car.size();
//         if(cn&1){ // odd
//             cout << car[cn/2] << " ";
//         }else{ // even
//             cout << min(car[cn/2],car[cn/2-1]) << " ";
//         }
//     }
//     cout << "\n";
// }

void solve(vector<int> &ar, int n){
    priority_queue<int> leftQ;
    priority_queue<int, vector<int>, greater<int>> rightQ;
    // left max q, right min q
    for(int i = 0; i < n; i++){
        int key = ar[i];
        if(leftQ.empty() || key <= leftQ.top()){
            leftQ.push(key);
        }else{
            rightQ.push(key);
        }
        int ll = leftQ.size();
        int lr = rightQ.size();
        if(ll-lr > 1 || lr > ll){
            if(ll < lr){
                leftQ.push(rightQ.top()); rightQ.pop();
            }else{
                rightQ.push(leftQ.top()); leftQ.pop();
            }
        }
        if(ll == lr){
            cout << min(leftQ.top(), rightQ.top()) << " ";
        }else{
            cout << leftQ.top() << " ";
        }
    }
    cout << "\n";
}

int main(){
    fast
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> ar(n);
        for(int i = 0; i < n; i++)
            cin >> ar[i];
        solve(ar, n);
    }
    return 0;
}