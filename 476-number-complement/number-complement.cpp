class Solution {
public:
    int findComplement(int n) {
        if(n==0)    return 1;
        int ans=0;
        int i=0;
        while(n){
            int isOne=(n&1) ;
            if(isOne){   // 1
                ans= ans|(0<<i);
            }else{        // 0
                ans= ans|(1<<i);
            }
            i++;
            n=n>>1;
        }
        return ans;
    }
};