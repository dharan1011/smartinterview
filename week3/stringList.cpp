#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool check(vector<string> &arr, string word, int index){
    if(index == word.size()){
        return true;
    }
    for(int i = index; i < word.size(); i++){
        string ss = word.substr(index, i);
        if(find(arr.begin(), arr.end(), ss) != arr.end()){
            if(check(arr, word, i + 1)){
                return true;
            }
        }
    }
    return false;
}

int count(vector<string> &arr, string word, int index){
    if(index == word.size()){
        return 1;
    }
    int cnt = 0;
    for(int i = index; i < word.size(); i++){
        string ss = word.substr(index, i);
        if(find(arr.begin(), arr.end(), ss) != arr.end()){
            cnt += count(arr, word, i + 1);
    }
    return cnt;
}

