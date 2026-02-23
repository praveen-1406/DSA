class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<string>st;
        int i=0,j=k-1;
        while(j<s.size()){
            st.insert(s.substr(i,j-i+1));
            i++;
            j++;
        }
        return st.size()==(1<<k);
    }
};