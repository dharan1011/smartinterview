#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

bool canAllot(vector<int> &arr, int student, int pages){
    int sum = 0;
    int sc = 1;
    for(int x : arr){
        sum += x;
        if(sum > pages){
            sum = x;
            sc++;
        }
    }
    return sc <= student;
}

int books(vector<int> &A, int B) {
    if(B > A.size()){
        return -1;
    }
    /*
    if B == 1, and N > 1 Then i have to allot all books to once student. So This will be my upper limit
    If B == N, B-1 containes pages less book B which container MAX page. In This is i will have to alllot that max B to atleast one student.
    So this will be my lower limit
    */
   int lo = *max_element(A.begin(), A.end());
   int hi = accumulate(A.begin(), A.end(), 0);

   while (lo < hi)
   {
       int mid = lo + (hi - lo) / 2;
       if(canAllot(A,B,mid)){
           hi = mid;
       }else{
           lo = mid + 1;
       }
   }
   return lo;
}
