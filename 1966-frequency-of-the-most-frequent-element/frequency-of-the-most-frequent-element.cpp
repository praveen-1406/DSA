class Solution {
    // int binarySearch(int targetIdx,int k,vector<int>&nums,vector<long>&prefixSum){
    //     int target=nums[targetIdx];
    //     int l=0,r=targetIdx;
    //     int bestIdx=targetIdx;
    //     while(l<=r){
    //         int mid=l+(r-l)/2;
    //         int count=(targetIdx-mid+1);
    //         long windowSum=1LL*count*target;
    //         long curSum=prefixSum[targetIdx]-prefixSum[mid]+nums[mid];
    //         long ops=windowSum-curSum;
    //         if(ops>k){
    //             l=mid+1;
    //         }else{
    //             bestIdx=mid;
    //             r=mid-1;
    //         }
    //     }
    //     return targetIdx-bestIdx+1;
    // }
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n=nums.size();
        sort(begin(nums),end(nums));
        // vector<long>prefixSum(n);
        // prefixSum[0]=nums[0];
        // for(int i=1;i<n;i++){
        //     prefixSum[i]=prefixSum[i-1]+nums[i];
        // }
        // int result=0;
        // for(int targetIdx=0;targetIdx<n;targetIdx++){
        //     result=max(result,binarySearch(targetIdx,k,nums,prefixSum));
        // }
        // return result;
        int result=0;
        int l=0;
        long curSum=0;
        for(int r=0;r<n;r++){
            int target=nums[r];
            long windowSum=1LL*(r-l+1)*target;
            curSum+=nums[r];
            long ops=windowSum-curSum;
            while(ops>k){
                curSum-=nums[l];
                l++;
                ops=1L*(r-l+1)*target-curSum;
            }
            result=max(result,(r-l+1));
        }
        return result;
    }
};