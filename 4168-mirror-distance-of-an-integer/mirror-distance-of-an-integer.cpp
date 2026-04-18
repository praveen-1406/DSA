class Solution {
public:
    int mirrorDistance(int n) {
        int r=0,val=n;
        while(val){
            r=r*10+val%10;
            val/=10;
        }
        return abs(n-r);
    }
};