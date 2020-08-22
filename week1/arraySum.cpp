#include<iostream>
#include<vector>
using namespace std;
int addVectorSum(vector<int> arr){
    int sum = 0;
    for(int x : arr){
        sum += x;
    }
    return sum;
}

int main(){
    return 0;
}
