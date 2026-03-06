class Solution {
public:
    bool checkOnesSegment(string s) {
        int ones=0;
        bool seg=0;
        for(int i=1;i<s.size();i++){
            if(s[i]=='1' && !seg) {
                ones++;
            }else if(s[i]=='0' && s[i-1]=='1'){
                seg=1;
            }else if(s[i]=='1' && seg){
                return false;
            }

        }
        return true;
    }
};