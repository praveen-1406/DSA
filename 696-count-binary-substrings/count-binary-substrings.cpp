class Solution {
public:
    int countBinarySubstrings(string s) {
        int count=0;
        int zeros=0,prezeros=0,ones=0,preones=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='0'){
                if(ones!=0){
                    preones=ones;
                    ones=0;
                }
                zeros++;
                if(preones>=zeros)  count++;
            }
            else if(s[i]=='1'){
                if(zeros!=0){
                    prezeros=zeros;
                    zeros=0;
                }
                ones++;
                if(prezeros>=ones)  count++;
            }
        }
        return count;
    }
};