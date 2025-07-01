class Solution {
public:
    string minWindow(string s, string t) {
        int cnt=0,mini=INT_MAX,l=0,r=0;
        int n=s.size(),m=t.size();
        int sIdx=-1;
        unordered_map<char,int>hash;
        for(int i=0;i<m;i++){
            hash[t[i]]++;
        }
        while(r<n){
            if(hash[s[r]]>0)    cnt++;
            hash[s[r]]--;
            while(cnt==m){
                if((r-l+1)<mini)    {
                    mini=(r-l+1);
                    sIdx=l;
                }
                hash[s[l]]++;
                if(hash[s[l]]>0)    cnt--;
                l++;
            }
            r++;
        }
        return sIdx==-1?"":s.substr(sIdx,mini);
    }
};