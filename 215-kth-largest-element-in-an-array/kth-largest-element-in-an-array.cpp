class Solution {
    int partitionIdx(vector<int>&nums,int l,int r){
        int p=nums[l],i=l,j=r;
        while(i<=j){
            if(nums[i]>p && nums[j]<p){
                swap(nums[i],nums[j]);
                i++;
                j--;
            }
            if(i<=r && nums[i]<=p)    i++;
            if(j>=l+1 && nums[j]>=p)    j--;
        }
        swap(nums[l],nums[j]);
        return j;

    }
public:
    int findKthLargest(vector<int>& nums, int k) {
        // priority_queue<int,vector<int>,greater<int>>heap; //min-heap
        // for(int i=0;i<nums.size();i++){
        //     heap.push(nums[i]);
        //     if(heap.size()>k)   heap.pop();
        // }
        // return heap.top();
        int n=nums.size();
        if(k>n) return -1;
        int l=0,r=n-1;
        int pivot;
        while(true){
            pivot= partitionIdx(nums,l,r);
            if(pivot==n-k)  break;          //kth index from last 0-based indexing
            else if(pivot>n-k)   r=pivot-1;
            else    l=pivot+1;
        }
        return nums[pivot];
    }
};