class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans="";
        for(auto i:words){
            int w=0;
            for(auto a:i){
                w+=weights[a-'a'];
            }
            w%=26;
            ans+=('a'+25-w);
        }
        return ans;
    }
};