#include <iostream>
#include <algorithm>
#include <vector>
#define fast cin.sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

void solve(vector<int>& A, vector<int>& B, int n){
    int wins = 0;
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    int posA = 0;
    int posB = 0;
    while (posA < n && posB < n)
    {
        if(A[posA] <= B[posB]){
            posA++;
        }else{
            posB++;
            posA++;
            wins++;
        }
    }
    
    cout << wins << "\n";
}

int main(){
    fast
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        vector<int> A(n), B(n);
        for(int i = 0; i < n; i++)
            cin >> A[i];
        for(int i = 0; i < n; i++)
            cin >> B[i];
        solve(A,B,n);
    }
}