class Solution {
    bool f(int start,string &word,unordered_set<string>&st,vector<int>&dp){
        if(word.size()==start)    return true;
        if(dp[start]!=-1)   return dp[start];
        for(int i=start;i<word.size();i++){
            string prefix=word.substr(start,i-start+1);
            if(st.find(prefix)!=st.end()){
                if(f(i+1,word,st,dp))  return dp[start]= true;
            }
        }
        return dp[start]= false;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>st;
        vector<int>dp(s.size(),-1);
        for(auto it:wordDict){
            st.insert(it);
        }
        return f(0,s,st,dp);
    }
};