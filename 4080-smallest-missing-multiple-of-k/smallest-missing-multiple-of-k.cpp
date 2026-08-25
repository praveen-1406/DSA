class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int>st(nums.begin(),nums.end());
        int m=1;

        for(int i=1;i<=100;i++){
            if(st.find(k*i)==st.end())   return k*i;
            m++;
        }
        return k*m;
    }
};