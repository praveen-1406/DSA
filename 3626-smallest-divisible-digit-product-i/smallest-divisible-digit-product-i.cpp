class Solution {
    int prodDigit(int n){
        int p=1;
        while(n){
            p*= (n%10);
            n/=10;
        }
        return p;
    }
public:
    int smallestNumber(int n, int t) {
        for(int i=n;i<=100;i++){
            int p=prodDigit(i);
            if(p%t==0)  return i;
        }
        return -1;
    }
};