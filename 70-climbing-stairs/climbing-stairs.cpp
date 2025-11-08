class Solution {
public:
    int climbStairs(int n) {
        if(n<=2)    return n;
        int prev2=1,prev=2,curi;
        for(int i=3;i<=n;i++){
            curi=prev2+prev;
            prev2=prev;
            prev=curi;
        }
        return curi;
    }
};