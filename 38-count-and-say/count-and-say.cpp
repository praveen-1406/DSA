class Solution {
public:
    string f(string s){
        string ans="";
        int cnt=1;
        for(int i=1;i<s.length();i++){
            if(s[i]==s[i-1]){
                cnt++;
            }else{
                ans+= to_string(cnt) + s[i-1];
                cnt=1;
            }
        }
        ans+= to_string(cnt) + s[s.size()-1];
        return ans;
    }
    string countAndSay(int n) {
        string ans="1";
        for(int i=1;i<n;i++){
            ans=f(ans);
        }
        return ans;
    }
};