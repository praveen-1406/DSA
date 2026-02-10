class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        unordered_map<int,int>even,odd;
        int l=0,r=0;
        int n=nums.size();
        int mlen=0;
        for(int l=0;l<n;l++){
            even.clear();
            odd.clear();
            for(int r=l;r<n;r++){
                if((nums[r] & 1)==0)    even[nums[r]]++;
                else    odd[nums[r]]++;
                if(even.size()==odd.size())     mlen=max(mlen,(r-l+1));
            }
        }
        return mlen;
    }
};