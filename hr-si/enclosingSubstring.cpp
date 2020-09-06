#include <iostream>
#include <vector>
#include <string>
#define fast cin.sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

bool cmpr(const vector<int> &a, vector<int> &b){
    // cmpr a and b wrt a
    for(int i = 0; i < 26; i++){
        if(a[i]){
            if(b[i] < a[i]){ // b[i] >= a[i]
                return false;
            }
        }
    }
    return true;
}

bool check(const vector<int> &fta, string &b, int win){
    vector<int> ftb(26, 0);
    for(int i = 0; i < win; i++){
        ftb[b[i]-'a']++;
    }
    if(cmpr(fta, ftb)){
        return true;
    }
    int bn = b.size();
    for(int i = win; i < bn; i++){
        ftb[b[i - win] - 'a']--; // remove leaving character
        ftb[b[i] - 'a']++; // add current character
        if(cmpr(fta, ftb)){ // check if there exists a window in b which contains all character of
            return true;
        }
    }
    return false; // return false there is not window of size win which consister all characeter of a.
}

int solve(string &a, string &b){
    int lo = 0;
    int hi = b.size();
    vector<int> fta(26, 0);
    for(char c : a){
        fta[c-'a']++;
    }
    while (lo < hi)
    {
        int mid = lo + (hi - lo) / 2;
        if(check(fta, b, mid)){
            hi = mid;
        }else{
            lo = mid + 1;
        }
    }
    return check(fta, b, b.size())? lo: -1;
}

int main(){
    fast
    string a, b;
    int t;
    cin >> t;
    while(t--){
        cin >> a >> b;
        cout << solve(a,b) << "\n";
    }
    return 0;
}