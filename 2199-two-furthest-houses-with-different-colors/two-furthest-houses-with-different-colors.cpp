class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int ans=INT_MIN;
        // for(int i=0;i<colors.size();i++){
        //     for(int j=i+1;j<colors.size();j++){
        //         if(colors[i]!=colors[j])    ans=max(ans,j-i);
        //     }
        // }
        // return ans;
        int j=colors.size()-1,i=0;
        for(;i<colors.size();i++){
            if(colors[i]!=colors[j])    ans=max(ans,j-i);
            if(colors[i]!=colors[0])    ans=max(ans,i);
        }
        return ans;
    }
};