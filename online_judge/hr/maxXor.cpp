#include <iostream>
using namespace std;

int main(int agrc, char **argv){
    int l, r;
    cin >> l >> r;
    for(int i = 0; i < 9; i++){
        int bl = (l & (1 << i));
        int rl = (r & (1 << i));
        if(bl == rl){
            int tl = l ^ (1 << i);
            int tr = r ^ (1 << i);
            if(tl >= l && tl <= r){
                l = tl;
            }else if(tr >= l && tr <= r){
                r = tr;
            }
        }
    }
    cout << (l ^ r);
    return 0;
}
/**
 * L = 8
 * R = 20
 * LSB -----> MSB
 * L : 0 0 0 1 0 0 0 0
 * R : 0 0 1 0 1 0 0 0 
 *     x x
 *
 * I can toogle xth bit of L and the new number is still in range.
 *
 * Now the xor of both the number will be S
 * S : 1 1 1 1 1 0 0 0
 * */
