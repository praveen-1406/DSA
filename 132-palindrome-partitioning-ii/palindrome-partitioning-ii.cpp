class Solution {
    bool isPalindrome(string &s){
        int i=0,j=s.size()-1;
        while(i<j){
            if(s[i]!=s[j])  return false;
            i++;
            j--;
        }
        return true;
    }
    // long long f(int i,int j,string &s,vector<vector<int>>&dp){
    //     if(i>j)     return 0;
    //     if(isPalindrome(i,j,s))    return 0;
    //     if(dp[i][j]!=-1)    return dp[i][j];
    //     long long cuts=INT_MAX;
    //     for(int k=i+1;k<=j;k++){
    //         cuts=min(cuts,1+f(i,k-1,s,dp)+f(k,j,s,dp));
    //     }
    //     return dp[i][j] = cuts;
    // }
    int f(int i,string &s,vector<int>&dp){
        if(i==s.size())    return 0;
        if(dp[i]!=-1)   return dp[i];
        int minCost=INT_MAX;
        string temp="";
        for(int j=i;j<s.size();j++){
            temp+=s[j];
            if(isPalindrome(temp)){
                int cost=1+f(j+1,s,dp);
                minCost=min(minCost,cost);
            }
        }
        return dp[i] = minCost;
    }
public:
    int minCut(string s) {
        int n=s.size();
        // vector<vector<int>>dp(n,vector<int>(n,-1));
        // return f(0,n-1,s,dp);
        vector<int>dp(n,-1);
        return f(0,s,dp)-1;
    }
};