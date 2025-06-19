class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int maxidx=0,n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]>nums[maxidx])  maxidx=i;
        }
        stack<int>st;
        vector<int>nge(n);
        for(int i=maxidx;i>=0;i--){
            while(!st.empty() && nums[i]>=st.top()){
                st.pop();
            }
            if(st.empty())  nge[i]=-1;
            else    nge[i]=st.top();
            st.push(nums[i]);
        }
        for(int i=n-1;i>maxidx;i--){
            while(!st.empty() && nums[i]>=st.top()){
                st.pop();
            }
            if(st.empty())  nge[i]=-1;
            else    nge[i]=st.top();
            st.push(nums[i]);
        }
        return nge;
    }
};