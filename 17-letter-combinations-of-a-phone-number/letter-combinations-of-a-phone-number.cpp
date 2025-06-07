class Solution {
public:

    void func(int idx,string&digits,vector<string>&ans,string temp,map<int,string>&mp){
        if(idx==digits.size()){
            if(!temp.empty())    ans.push_back(temp);
            return;
        }
        string s=mp[digits[idx]-'0'];
        for(int i=0;i<s.size();i++){
            
            func(idx+1,digits,ans,temp+s[i],mp);
 
        }
    }

    vector<string> letterCombinations(string digits) {
        map<int,string>mp;
        mp[2]="abc",mp[3]="def",mp[4]="ghi",mp[5]="jkl",mp[6]="mno",mp[7]="pqrs",mp[8]="tuv",mp[9]="wxyz";
        vector<string>ans;
        func(0,digits,ans,"",mp);
        return ans;
    }
};