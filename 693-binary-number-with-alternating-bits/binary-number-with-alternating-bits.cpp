class Solution {
public:
    bool hasAlternatingBits(int n) {
        // int i=31;
        // for(i;i>=0;i--){
        //     int bit=(((1<<i)&n)==0)?0:1;
        //     if(bit==1)    break;
        // }
        // bool isOne=1;
        // for(i;i>=0;i--){
        //     int bit=(((1<<i)&n)==0)?0:1;
        //     if(bit!=isOne)  return false;
        //     isOne=!isOne;
        // }
        // return true;

        // int hsbit=log2(n);
        // bitset<32>b(n);
        // for(int i=0;i<=hsbit;i++){
        //     if(b[i]==b[i+1])    return false;
        // }
        // return true;

        int curbit=n%2;
        n/=2;
        while(n){
            if(curbit==n%2)     return false;
            curbit=n%2;
            n/=2;

        }
        return true;
    }
};