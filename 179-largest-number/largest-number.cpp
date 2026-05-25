class Solution {
public:
    string largestNumber(vector<int>& nums) {
        int n=nums.size();
        vector<string>v;
        for(auto it:nums){
            v.push_back(to_string(it));
        }
        sort(v.begin(),v.end(),[](string a,string b){
            return a+b <b+a;
        });
        string lnum="";
        for(int i=n-1;i>=0;i--){
            lnum+=v[i];
        }
        bool allzero=true;
        for(auto it:lnum){
            if(it!='0'){
                allzero=false;
                break;
            }
        }
        if(allzero) return "0";
        return lnum;
    }
};