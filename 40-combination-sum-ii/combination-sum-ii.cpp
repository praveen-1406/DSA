class Solution {
public:

    void func(int idx,int target,vector<vector<int>>&ans,vector<int>&temp,vector<int>&cand){
        if(target<0)    return;
        if(target==0){
            ans.push_back(temp);
            return;
        }
        if(idx==cand.size())     return;

        for(int i=idx;i<cand.size();i++){
            if(i!=idx && cand[i]==cand[i-1]){
              continue;
            }
            temp.push_back(cand[i]);
            func(i+1,target-cand[i],ans,temp,cand);
            temp.pop_back();
        }


    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        
        vector<vector<int>>ans;
        vector<int>ds;
        func(0,target,ans,ds,candidates);

        
        
        return ans;
    }
};