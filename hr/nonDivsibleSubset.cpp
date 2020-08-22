#include <vector>
#include <algorithm>
using namespace std;

int nonDivisibleSubset(int k, vector<int> s) {
    /*
        (a + b) % k = ((a%k) + (b%k)) % k
    */
   int n = s.size();
   vector<int> ft(k, 0);
   for(int i = 0; i < n; i++){
       ft[s[i]%k]++;
   }

   int res = 0;
   int h = (k-1)/2;
   for(int i = 1; i <= h; i++){
       res += max(ft[i], ft[k-i]);
   }
   if(h&1){
       res += ft[h+1];
   }
   if(ft[0]) res++;
   return res;
}

// 0 1 2 3 4 5