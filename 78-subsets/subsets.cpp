class Solution {
public:

    //By using bit manipulation
    // void powerSet(vector<int>num,vector<vector<int>>&ans){
    //     int n=num.size();
    //     for(int i=0;i< (1<<n);i++){
    //         vector<int>v={};
    //         for(int j=0;j<n;j++){
    //             if((i & (1<<j))!=0){
    //                 v.push_back(num[j]);
    //             }
    //         }
    //         ans.push_back(v);
    //     }
    // }

    //by Recursion
    void rec(int idx,vector<int> &temp,vector<vector<int>> &ans,vector<int>&num){
        if(idx>=num.size()){
            ans.push_back(temp);
            return;
        }
        temp.push_back(num[idx]);
        rec(idx+1,temp,ans,num);
        temp.pop_back();
        rec(idx+1,temp,ans,num);
    }


    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        // powerSet(nums,ans);   
        vector<int>temp={};
        rec(0,temp,ans,nums) ;
        return ans;
    }
};