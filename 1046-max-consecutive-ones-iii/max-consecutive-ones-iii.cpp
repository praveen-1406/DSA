class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        // queue<int>q;
        int l=0,r=0,maxi=0;
        int zeros=0;
        while(r<n){
            if(nums[r]==0){  
                zeros++;
                // q.push(r);
            }
            if(zeros>k){
                // l=q.front()+1;
                // q.pop();
                // zeros--;
                if(nums[l]==0)  zeros--;
                l++;
            }
            
            //     maxi=max(maxi,r-l+1);
            // r++;
            if(zeros<=k)    maxi=max(maxi,r-l+1);
            r++;
        }
        return maxi;
    }
};