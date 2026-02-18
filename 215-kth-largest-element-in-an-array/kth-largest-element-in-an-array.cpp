class Solution {
    int partitionIdx(vector<int>&nums,int l,int r){
        int p=nums[l],i=l+1,j=r;
        while(i<=j){
            if(nums[i]<p && nums[j]>p){
                swap(nums[i],nums[j]);
                i++;
                j--;
            }
            if(nums[i]>=p)    i++;
            if(nums[j]<=p)    j--;
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
        int l=0,r=n-1;
        int pivot;
        while(true){
            pivot= partitionIdx(nums,l,r);
            if(pivot==k-1)  break;
            else if(k-1<pivot)   r=pivot-1;
            else    l=pivot+1;
        }
        return nums[pivot];
    }
};