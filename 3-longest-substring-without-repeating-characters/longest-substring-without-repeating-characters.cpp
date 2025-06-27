class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // int maxLength=0;
        // int n=s.size();
        // int l=0,r=0;
        // map<char,int>mp;
        // while(r<n){
        //     mp[s[r]]++;
        //     while(mp[s[r]]>1){
        //         mp[s[l]]--;
        //         l++;
        //     }
        //     if(mp[s[r]]==1){
        //         maxLength=max(maxLength,r-l+1);
        //     }
        //     r++;
        // }
        // return maxLength;
        int n=s.size();
        int l=0,r=0,maxi=0;
        unordered_map<char,int>mp;
        while(r<n){
            if(mp.find(s[r])!=mp.end()){
                if(mp[s[r]]>=l) l=mp[s[r]]+1;
            }
            mp[s[r]]=r;
            int len=r-l+1;
            maxi=max(maxi,len);
            r++;
        }
        return maxi;
    }
};