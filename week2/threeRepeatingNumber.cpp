#include <iostream>
using namespace std;

int solve(int arr[], int n){
    int res = 0;
    for(int i = 0; i < 32; i++){
        int c = 0;
        for(int j = 0; j < n; j++){
            if(arr[j] & (1 << i)){
                c++;
            }
        }
        if(c%3){
            res |= (1 << i);
        }
    }
    return res;
}

int main(int agrc, char **argv){

    return 0;
}

