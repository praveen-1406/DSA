class Solution {
public:
    int singleNumber(vector<int>& nums) {

        //Better 1:
        // int ans=0;
        // for(int bitIdx=0;bitIdx<32;bitIdx++){
        //     int cnt=0;
        //     for(int j=0;j<nums.size();j++){
        //         if(nums[j] & (1<<bitIdx)) cnt++;
        //     }
        //     if(cnt%3==1)    ans=ans | 1<<bitIdx;
        // }
        // return ans;


        // Better2:
        if(nums.size()==1)  return nums[0];
        sort(nums.begin(),nums.end());
        int i=1;
        while(i<nums.size()){
            if(nums[i-1]!=nums[i] ) return nums[i-1];
            i+=3;
        }
        return nums[nums.size()-1];



    }
};












