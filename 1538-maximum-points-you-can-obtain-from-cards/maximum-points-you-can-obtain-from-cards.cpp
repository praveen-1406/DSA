class Solution {
public:
    int maxScore(vector<int>& cp, int k) {
        int lsum=0,rsum=0;
        int maxsum=0,n=cp.size();
        for(int i=0;i<k;i++){
            lsum+=cp[i];
        }
        maxsum=lsum;
        int ridx=n-1;
        for(int i=k-1;i>=0;i--){
            lsum-=cp[i];
            rsum+=cp[ridx];
            ridx--;
            maxsum=max(maxsum,lsum+rsum);
        }
        return maxsum;
    }
};