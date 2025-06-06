class Solution {
public:

    void func(int idx,vector<vector<int>>&ans,vector<int>&temp,vector<int>&cand,int target,int sum){
        if(sum>target)  return;
        if(sum==target){
            ans.push_back(temp);
            return;
        }
        if(idx==cand.size()) return;

        temp.push_back(cand[idx]);
        sum+=cand[idx];
        func(idx,ans,temp,cand,target,sum);
        // func(idx+1,ans,temp,cand,target,sum);

        temp.pop_back();
        sum-=cand[idx];
        func(idx+1,ans,temp,cand,target,sum);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>temp={};
        func(0,ans,temp,candidates,target,0);
        return ans;
    }
};