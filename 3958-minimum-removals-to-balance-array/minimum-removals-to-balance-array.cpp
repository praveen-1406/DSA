class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int len=0,maxLen=INT_MIN;
        int i=0,j=0;
        while(j<n){
            if((long long)nums[j]<=k*(long long)nums[i]){
                j++;
                len++;
            }else{
                i++;
                len--;
            }

            maxLen=max(maxLen,len);
        }
        return n-maxLen;

    }
};