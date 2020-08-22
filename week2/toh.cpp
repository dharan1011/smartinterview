#include <iostream>
using namespace std;
void toh(int n, char src, char dest, char temp){
    if(n == 1){
        cout << "Move Disk : " << n << " from " << src << " to " << dest << '\n';
        return;
    }
    toh(n-1, src, temp, dest);
    cout << "Move Disk : " << n << " from " << src << " to " << dest << '\n';
    toh(n-1,temp, dest, src);
}

int main(int agrc, char **argv){

    return 0;
}

