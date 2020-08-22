#include <iostream>
using namespace std;
int pwr(int a, int n){
    int res = 1;
    while(n){
        if(n&1){
            res *= a;
        }
        n >>= 1;
        a *= a;
    }
    return res;
}
int main(int agrc, char **argv){

    return 0;
}

