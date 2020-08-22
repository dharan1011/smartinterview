#include <vector>
using namespace std;
vector<int> plusOne(vector<int> &A) {
    int start = 0;
    int n = A.size();
    while(A[start] == 0) start++;
    vector<int> tempA(A.begin()+start, A.end());
    int c = 1;
    for(int i = tempA.size() - 1; i >= 0; --i){
        int sum = tempA[i] + c;
        tempA[i] = sum % 10;
        c = sum / 10;
        if(c == 0){
            break;
        }
    }
    if(c){
        tempA.push_back(-1);
        int j = tempA.size()-2;
        while(j >= 0){
            tempA[j+1] = tempA[j];
            j--;
        }
        tempA[0] = c;
    }
    return tempA;
}
