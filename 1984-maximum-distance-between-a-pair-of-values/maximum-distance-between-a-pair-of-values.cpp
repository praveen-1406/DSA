class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        int j=m-1;
        int i=min(n-1,j);
        int ans=0;
        while(i>=0 && j>=0){
            if(nums1[i]<=nums2[j] && i<=j){
                ans=max(ans,j-i);
                i--;
            }else if(j>i){
                j--;
            }else{
                i--;
                j--;
            }
        }
        return ans;
    }
};