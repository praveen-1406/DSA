class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {
        int n=arr.size();
        sort(arr.begin(),arr.end());
        vector<vector<int>>ans;
        ans.push_back(arr[0]);
        for(int i=1;i<n;i++){
            if(ans[ans.size()-1][1]<arr[i][0]){
                ans.push_back(arr[i]);
            }else{
                ans[ans.size()-1][1]=max(ans[ans.size()-1][1],arr[i][1]);
            }
        }
        return ans;
    }
};