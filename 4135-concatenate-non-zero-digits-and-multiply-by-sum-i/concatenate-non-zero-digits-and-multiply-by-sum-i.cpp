class Solution {
public:
    long long sumAndMultiply(int n) {
        long long sum=0;
        long long x=1;
        while(n){
            long long a=n%10;
            if(a!=0){
                long long digits=floor(log10(x)+1);
                x=a*pow(10,digits)+x;
                sum+=a;
            }
            n/=10;
        }
        x/=10;
        if(sum!=0) return sum*x;
        return 0;
    }
};