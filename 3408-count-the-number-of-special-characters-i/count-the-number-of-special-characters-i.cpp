class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_set<int>low,upp;
        int cnt=0;
        for(auto it:word){
            if('a'<=it && it<='z'){
                low.insert(it-'a');
            }else{
                upp.insert(it-'A');
            }
        }
        for(char ch='a';ch<='z';ch++){
            int idx=ch-'a';
            if(low.find(idx)!=low.end() && upp.find(idx)!=upp.end())  cnt++;
        }
        return cnt;
    }
};