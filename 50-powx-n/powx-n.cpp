class Solution {
public:
    double myPow(double x, int n) {
        //Binary Exponentiation

        //By iteration
        // double ans=1.0;
        // long long nn=n;
        // if(nn<0)    nn=-nn;
        // while(nn){
        //     if(nn%2){
        //         ans=ans*x;
        //         nn=nn-1;
        //     }else{
        //         x=x*x;
        //         nn=nn/2;
        //     }
        // }
        // if(n<0) ans=1.0/ans;
        // return ans;
        long long N=n;
        double ans=1;
        if(N<0) N=-N;
        while(N){
            if(N%2==0){
                N/=2;
                x=x*x;
            }else{
                N=N-1;
                ans*=x;
            }
        }
        if(n<0) ans=1.0/ans;
        return ans;
    }
};