#include <iostream>
using namespace std;

unsigned int reverseBits(unsigned int A){
    unsigned int res = 0, one = 1;
    for(int i = 0; i < 32; i++){
        if(A & (one << i)){
            res |= (one << (32 - i - 1));
        }
    }
    return res;
}

int main(int agrc, char **argv){
    unsigned int A = 3;
    cout << reverseBits(A);
    return 0;
}

