class Solution {
public:
    bool checkStrings(string s1, string s2) {
        int n=s1.size();
        unordered_map<char,int>even,odd;
        for(int i=0;i<n;i++){
            if(i & 1){
                odd[s1[i]]++;
            }else{
                even[s1[i]]++;
            }
        }
        for(int i=0;i<n;i++){
            if(i & 1){
                if(odd[s2[i]]==0)  return false;
                odd[s2[i]]--;
            }
            else{
                if(even[s2[i]]==0)    return false;
                even[s2[i]]--;
            }
        }
        return true;
    }
};