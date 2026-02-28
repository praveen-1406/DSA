class Solution {
    const int MOD=1e9+7;
public:
    int concatenatedBinary(int n) {
        long long val=0;
        for(int i=1;i<=n;i++){
            int digits=log2(i)+1;
            val=((val<<digits)|i)%MOD;
        }
        val=val%MOD;
        return (int)val;
    }
};