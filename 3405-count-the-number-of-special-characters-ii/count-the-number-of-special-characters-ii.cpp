class Solution {
public:
    int numberOfSpecialChars(string word) {
        // unordered_set<char>st(word.begin(),word.end());
        unordered_map<char,int>mp;
        for(int i=0;i<word.size();i++){
            if('a'<=word[i] && word[i]<='z'){
                mp[word[i]]=i;
            }else if(mp.find(word[i])==mp.end()){
                mp[word[i]]=i;
            }
        }
        int cnt=0;
        for(char ch='a';ch<='z';ch++){
            if(mp.find(ch)!=mp.end() && mp.find(ch-'a'+'A')!=mp.end() && mp[ch]<mp[ch-'a'+'A'] )   cnt++;
        }
        return cnt;
    }
};