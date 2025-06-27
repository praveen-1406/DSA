class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0,r=0,maxlen=0,maxf=0;
        int n=s.size();
        unordered_map<int,int >mp;
        while(r<n){
            mp[s[r]-'A']++;
            maxf=max(maxf,mp[s[r]-'A']);
            if((r-l+1)-maxf > k){
                mp[s[l]-'A']--;
                l++;
            }
            if((r-l+1)-maxf<=k){
                maxlen=max(maxlen,(r-l+1));
            }
            r++;
        }
        return maxlen;;
    }
};