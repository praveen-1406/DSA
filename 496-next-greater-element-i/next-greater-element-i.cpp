class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        // vector<int>nge(nums2.size());
        stack<int>st;
        unordered_map<int,int>mp;
        for(int i=nums2.size()-1;i>=0;i--){
            mp[nums2[i]]=i;
            while(!st.empty() && nums2[i]>=st.top()){
                st.pop();
            }
            if(st.empty())  mp[nums2[i]]=-1;
            else    mp[nums2[i]]=st.top();
            st.push(nums2[i]);
        }
        vector<int>ans(nums1.size());
        for(int i=0;i<nums1.size();i++){
            ans[i]=mp[nums1[i]];
        }
        return ans;
    }
};