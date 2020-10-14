#include <vector>
#include <cmath>
using namespace std;

const int MAX_N = 1e5 + 1;
vector<bool> isprime(MAX_N, true);

void generate_sieve(){
    isprime[0] = isprime[1] = false;
    for(int i = 2; i < MAX_N; i++){
        if(isprime[i]){ 
        /*
            if a number passes this condition that means
            there exists no from [2,i] number which can divide i.
            That means it is prime.
        */
        /*
            For each prime number rule out it multiple
        */
            for(int j = 2 * i; j < MAX_N; j += i){
                isprime[j] = false;
            }
        }
    }
}

void generate_sieve_opt(){
    isprime[0] = isprime[1] = false;
    /*
        The i loop can reduced with assumption that
        Let us say MAX_N - 1 is not a prime number
        That means there must be a factor of MAX_N which should
        <= sqrt(MAN-1). So the outer i loop can sufficient if check from
        2 to sqrt(n)
    */
    for(int i = 2; i * i < MAX_N; i++){
        if(isprime[i]){
            /*
                All the number which are less i * i, if it is not a prime
                than it must have factor which is less than i, will be ruled
                out by before reaching current number
            */ 
            for(int j = i * i; j < MAX_N; j += i){
                if(isprime[j])
                    isprime[j] = false;
            }
        }
    }
}

vector<int> generatePrime(int R){
    vector<bool> check(R+1, true);
    vector<int> res;
    res.reserve(R);
    for(int i = 2; i <= R; i++){
        if(check[i]){
            res.push_back(i);
            for(int j = i * i; j <= R; j += i){
                check[j] = false;
            }
        }
    }
    return res;
}
// b - a <= 1e5
int primeInRange(int a, int b){
    vector<int> primes = generatePrime(sqrt(b));
    vector<bool> check(b-a+1, true);
    for(int p : primes){
        if(p * p > b){
            break;
        }
        for(int j = p * p; j <= b; j += p){
            if(j >= a){
                check[j-a] = false;
            }
        }
    }
    int res = 0;
    for(int i = 0; i < check.size(); i++){
        if(a + i == 1) continue;
        if(check[i]){
            res++;
        }
    }
    return res;
}