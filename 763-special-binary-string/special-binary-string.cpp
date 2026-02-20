class Solution {
public:
    string makeLargestSpecial(string s) {
        int sum=0,start=0;
        vector<string>special;
        for(int i=0;i<s.size();i++){
            sum+=s[i]=='1'?+1:-1;
            if(sum==0){
                string inner=s.substr(start+1,i-start-1);
                special.push_back('1'+makeLargestSpecial(inner)+'0');
                start=i+1;
            }
        }
        sort(special.begin(),special.end(),greater<string>());
        string result="";
        for(string str:special){
            result+=str;
        }
        return result;
    }
};