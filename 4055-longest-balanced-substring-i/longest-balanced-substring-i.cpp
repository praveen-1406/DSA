class Solution {
    bool isBalanced(unordered_map<char,int>&mp){
        int freq=0;
        for(auto e:mp){
            if(freq==0){
                freq=e.second;
            }
            else{
                if(freq!=e.second)  return false;
            }
        }
        return true;
    }
public:
    int longestBalanced(string s) {
        int n=s.size();
        int mlen=1;
        for(int i=0;i<n;i++){
            unordered_map<char,int>mp;
            for(int j=i;j<n;j++){
                mp[s[j]]++;
                if(isBalanced(mp))  mlen=max(mlen,j-i+1);
            }
        }
        return mlen;
    }
};


