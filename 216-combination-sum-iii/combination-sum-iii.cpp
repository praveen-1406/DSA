class Solution {
public:
    //idx:1-9
    void func(int idx,int x,int n,int k,vector<vector<int>>&ans,vector<int>&temp){
        if(n<0)     return;
        if(idx==k){
            if(n==0){
                ans.push_back(temp);
            }
            return;
        }
        if(x>9)     return;


        temp.push_back(x);
        func(idx+1,x+1,n-x,k,ans,temp);

        temp.pop_back();
        func(idx,x+1,n,k,ans,temp);
        
        
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans={};
        vector<int>ds={};
        func(0,1,n,k,ans,ds);
        return ans;
    }
};