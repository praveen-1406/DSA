class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        for(int i=0;i<4;i++){
            // for(int j=0;j<4;j++){
                if(!(s1[i]==s2[i] || (i>=2 &&s1[i]==s2[i-2])||(i+2<4 && s1[i]==s2[i+2])))   return false;
            // }
        }
        return true;
    }
};