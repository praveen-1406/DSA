class Solution {
    string f(int n,string s,unordered_set<string>&st){
        if(n==0){
            if(st.find(s)==st.end())    return s;
            return "-1";
        }
        string s1=f(n-1,s+'0',st);
        string s2=f(n-1,s+'1',st);
        if(s1!="-1")    return s1;
        else return s2;
    }
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n=nums.size();
        unordered_set<string>st;
        for(auto i:nums){
            st.insert(i);
        }
        return f(n,"",st);
    }
};