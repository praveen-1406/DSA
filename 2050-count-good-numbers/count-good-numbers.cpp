
class Solution {
public:
    // binary exponentiation
    int M=1e9+7;
    long long pow(long long  a,long long b){
        if(b==0)    return 1;
        long long half=pow(a,b/2);
        long long result=(half*half)%M;
        if(b%2==1)  result=(result*a)%M;
        return result;
    }

    int countGoodNumbers(long long n) {
        long long primes=pow(4,n/2)%M;
        long long evens=pow(5,(n+1)/2)%M;
        return (long long)(primes*evens)%M;
    }
};