class Solution {
public:
    string removeKdigits(string num, int k) {
        if(k>=num.size())   return "0";
        stack<char>st;
        for(int i=0;i<num.size();i++){
            while(!st.empty() && st.top()>num[i] && k){
                st.pop();
                k--;
                // if(k==0)    break;
            }
            if(!(st.empty()&&num[i]=='0'))    st.push(num[i]);
        }
        while(k!=0 && !st.empty()){
            st.pop();
            k--;
        }
        vector<char>v;
        while(!st.empty()){
            v.push_back(st.top());
            st.pop();
        }
        reverse(v.begin(),v.end());
        string s=string(v.begin(),v.end());
        if(s.size())    return s;
        else    return "0";

    }
};