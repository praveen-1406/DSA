class Solution {
public:
    int maxFreqSum(string s) {
        map<char,int>mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }
        int maxv=0,maxc=0;
        for(auto it:mp){
            if(it.first=='a'||it.first=='e'||it.first=='i'||it.first=='o'||it.first=='u'){
                maxv=max(maxv,it.second);
            }
            else    maxc=max(maxc,it.second);
        }
        return maxv+maxc;
    }
};