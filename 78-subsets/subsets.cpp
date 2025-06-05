class Solution {
public:

    //By using bit manipulation
    void powerSet(vector<int>num,vector<vector<int>>&ans){
        int n=num.size();
        for(int i=0;i< (1<<n);i++){
            vector<int>v={};
            for(int j=0;j<n;j++){
                if((i & (1<<j))!=0){
                    v.push_back(num[j]);
                }
            }
            ans.push_back(v);
        }
        // sort(ans.begin(),ans.end());
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;

        powerSet(nums,ans);    
        return ans;
    }
};