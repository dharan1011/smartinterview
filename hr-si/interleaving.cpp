#include <iostream>
#include <algorithm>
#include <string>
#define fast cin.sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

void interleave(const string &a, const string &b, size_t posA, size_t posB, string res){
    if(posA ==  a.size() && posB == b.size()){
        cout << res << "\n";
        return;
    }
    if(posA < a.size() && posB < b.size()){
        if(a[posA] < b[posB]){
            interleave(a, b, posA+1, posB, res + a[posA]);
            interleave(a, b, posA, posB+1, res + b[posB]);
        }else{
            interleave(a, b, posA, posB+1, res + b[posB]);
            interleave(a, b, posA+1, posB, res + a[posA]);
            
        }
    }else if(posA < a.size())
        interleave(a, b, posA+1, posB, res + a[posA]);
    else if(posB < b.size())
        interleave(a, b, posA, posB+1, res + b[posB]);
}

void solve(const string &a,const string &b){
    string res = "";
    interleave(a,b,0,0,res);
}

int main(){
    fast
    int T;
    cin >> T;
    string a, b;
    int cnt = 1;
    while(T--){
        cin >> a >> b;
        cout << "Case #" << cnt++ << ":" << "\n";
        solve(a, b);
    }
}