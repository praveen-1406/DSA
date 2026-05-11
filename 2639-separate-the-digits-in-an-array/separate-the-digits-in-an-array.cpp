class Solution {
    void findDigits(int n,vector<int>&ans){
        vector<int>v;
        while(n){
            v.push_back(n%10);
            n/=10;
        }
        reverse(v.begin(),v.end());
        ans.insert(ans.end(),v.begin(),v.end());
    }
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int>ans;
        for(int n:nums){
            findDigits(n,ans);
        }  
        return ans; 
    }
};