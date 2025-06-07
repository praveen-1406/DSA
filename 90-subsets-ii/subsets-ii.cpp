class Solution {
public:

    void func(int idx,vector<int>&arr,vector<vector<int>>&ans,vector<int>temp){
        ans.push_back(temp);
        for(int i=idx;i<arr.size();i++){    //purpose of loop is to select unique elements
            if(i!=idx && arr[i]==arr[i-1])  continue;
            temp.push_back(arr[i]);
            func(i+1,arr,ans,temp);
            temp.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        func(0,nums,ans,{});
        return ans;
    }
};