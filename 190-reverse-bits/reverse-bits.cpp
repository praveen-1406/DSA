class Solution {

public:
    int reverseBits(int n) {
        int ans=0;
        for(int i=0;i<32;i++){
            int rmb=n&1;
            n>>=1;
            ans<<=1;
            ans=ans|rmb;
        }
        return ans;
    }
};